#include<iostream>
#include<list>
#include<map>

using namespace std;

#define DEBUG_LOG 0

class Diet{
public:
    Diet(unsigned int n) : number_of_dead(0), number_of_dont_receive(0),n(n)
    {
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
                alive_patients.erase(it);
            }
            alive_patients_idx++;
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
        }
    }

    void SetPatient(unsigned long long a, unsigned long long b, int c)
    {
        if( this->a[c-1] == NO_PATIENT)
        {
            list<unsigned int>::iterator it;

            for(it = alive_patients.begin(); it != alive_patients.end(); it++)
            {
                unsigned int idx = *it;
                if((c-1) < idx)
                {
                    break;
                }
            }

            alive_patients.insert(it,c-1);
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
    int n;
    list<unsigned int> alive_patients;
};

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

    Diet robot(n);

    robot.Initialize();

#if DEBUG_LOG
    robot.PrintRoomStatus();
#endif

    unsigned int q = 0;

    cin>>q;

    if(q < 1 || q > 100000)
    {
        return -1;
    }

    list<string> results;

    for(int i  = 0; i < q ; i++)
    {
        int type = 0;

        cin>>type;

        if(type == 1)
        {
            unsigned long long x = 0;

            cin>>x;

            results.push_back(robot.StupidRobotStartFeeding(x));
        }
        
        if(type == 2)
        {
            unsigned long long a = 0, b = 0, c =0;

            cin>>a;
            cin>>b;
            cin>>c;

#if DEBUG_LOG
            cout<<a<<" "<<b<<" "<<c<<endl;
#endif
            robot.SetPatient(a,b,c);
#if DEBUG_LOG
            robot.PrintRoomStatus();
#endif
        }
    }

    list<string>::iterator it;

    for(it = results.begin(); it != results.end(); it++)
    {
        cout<<*it<<endl;
    }

    return 0;
}