#include<iostream>
#include<list>
#include<map>
#include<thread>
#include<condition_variable>
#include<mutex>

using namespace std;

#define DEBUG_LOG 0

void PrintOutputs();
void Inputs();
void HandleInputs();

class Diet{
public:

    Diet(unsigned int n) : number_of_dead(0), number_of_dont_receive(0),n(n),sorted(false)
    {
        a = new unsigned long long[n]();
        b = new unsigned long long[n]();        
    }

    Diet() : number_of_dead(0), number_of_dont_receive(0),sorted(false)
    {
        
    }
    void SetN(unsigned int n)
    {
        this->n = n;
        a = new unsigned long long[n]();
        b = new unsigned long long[n]();
    }

    string StupidRobotStartFeeding(unsigned long long x)
    {
        string str_result;

        number_of_dead = 0;
        number_of_dont_receive = 0;

        #define NO_PATIENT 0

        int i = 0;
        list<unsigned int>::iterator it;
        int alive_patients_idx = 0;
        int list_size = alive_patients.size();
        list<list<unsigned int>::iterator> remove_list;

        if(! sorted)
        {
            alive_patients.sort();
            sorted = true;
        }

        for(it = alive_patients.begin(); it != alive_patients.end(); it++)
        {
            unsigned int idx = *it;
            
            if( x < a[idx])
            {
                break;
            }

            x = x - a[idx];

            if( x > b[idx])
            {
                number_of_dead++;
                a[idx] = NO_PATIENT;
                b[idx] = NO_PATIENT;
                //alive_patients.erase(it);
                remove_list.push_back(it);
            }
            alive_patients_idx++;
        }

        list<list<unsigned int>::iterator>::iterator remove_it;

        for(remove_it = remove_list.begin(); remove_it != remove_list.end(); remove_it++)
        {
            alive_patients.erase(*remove_it);
        }

        number_of_dont_receive = list_size - alive_patients_idx;

        str_result = to_string(number_of_dead) + " " + to_string(number_of_dont_receive);

        return str_result;
    }

    void Initialize()
    {
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            cin>>b[i];
            alive_patients.push_back(i);
            sorted = true;
        }
    }

    void SetPatient(unsigned long long a, unsigned long long b, int c)
    {
        if( this->a[c-1] == NO_PATIENT)
        {
            alive_patients.push_back(c-1);
            sorted = false;
        }
        
        this->a[c-1] = a;
        this->b[c-1] = b;
    }

#if DEBUG_LOG
    void PrintRoomStatus()
    {
        for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
#endif

private:
    unsigned int number_of_dead;
    unsigned int number_of_dont_receive;
    unsigned long long *a;
    unsigned long long *b;
    unsigned int n;
    list<unsigned int> alive_patients;
    bool sorted;
};

list<string> results;
Diet robot;
condition_variable end_cv;
condition_variable output_cv;
mutex output_mtx;
mutex end_mtx;
bool end_signal = false;
unsigned long long **input_value;
unsigned int q;

int main()
{
    unsigned int n = 0;

    cin>>n;

    if(n < 1 || n > 100000)
    {
        return -1;
    }

#if DEBUG_LOG
    cout<<n<<endl;
#endif

    //Diet robot(n);
    robot.SetN(n);

    robot.Initialize();

#if DEBUG_LOG
    robot.PrintRoomStatus();
#endif

    q = 0;

    cin>>q;

    if(q < 1 || q > 100000)
    {
        return -1;
    }

    input_value = new unsigned long long*[q];

    for(unsigned int i = 0; i < q; i++)
    {
        input_value[i] = new unsigned long long[4];
    }

#define TYPE 0
#define X 1
#define A 1
#define B 2
#define C 3

    thread input_thread(Inputs);
    input_thread.join();

    thread handle_thread(HandleInputs);
    handle_thread.join();

    thread output_thread(PrintOutputs);
    output_thread.join();

    unique_lock<mutex> output_lk(output_mtx);
    output_cv.notify_one();
    //must input wait signal until print outputs is done.

    unique_lock<mutex> end_lk(end_mtx);
    if(! end_signal )
    {
        end_cv.wait(end_lk);
    }
    
    for(int i = 0; i < q ; i++)
    {
        delete [] input_value[i];
    }

    delete [] input_value;

    return 0;
}

void Inputs()
{
    for(int i  = 0; i < q ; i++)
    {
        int type = 0;

        cin>>type;

        input_value[i][TYPE] = type;

        if(type == 1)
        {
            unsigned long long x = 0;

            cin>>x;
            input_value[i][X] = x;
        }
        
        if(type == 2)
        {
            unsigned long long a = 0, b = 0, c =0;

            cin>>a;
            cin>>b;
            cin>>c;

            input_value[i][A] = a;
            input_value[i][B] = b;
            input_value[i][C] = c;
        }
    }
}

void HandleInputs()
{
    for(int i  = 0; i < q ; i++)
    {
        int type = input_value[i][TYPE];

        if(type == 1)
        {
            unsigned long long x = input_value[i][X];

            results.push_back(robot.StupidRobotStartFeeding(x));
        }
        
        if(type == 2)
        {
            unsigned long long a = input_value[i][A], b = input_value[i][B], c = input_value[i][C];

#if DEBUG_LOG
            cout<<a<<" "<<b<<" "<<c<<endl;
#endif
            robot.SetPatient(a,b,c);
#if DEBUG_LOG
            robot.PrintRoomStatus();
#endif
        }
    }
    results.push_back("last");
}

void PrintOutputs()
{
    while(1)
    {
        unique_lock<mutex> output_lk(output_mtx);
        //output_cv.wait(output_lk);

        while(1)
        {
            if(results.empty())
            {
                break;
            }
            string result_str = results.front();
            results.pop_front();
            if(result_str == "last")
            {
                end_signal = true;

                unique_lock<mutex> end_lk(end_mtx);
                end_cv.notify_all();
                return;
            }
            cout<<result_str<<endl;
        }
    }
}