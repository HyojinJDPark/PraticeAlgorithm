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
        int alive_patients_idx = 0;
        unsigned int map_size = map_alive_patients.size();
        list<map<unsigned int,unsigned int>::iterator> remove_list;
        map<unsigned int, unsigned int>::iterator map_it;
        map<unsigned int, unsigned int> new_map;

        for(map_it = map_alive_patients.begin(); map_it != map_alive_patients.end(); map_it++)
        {
            if( x < a[map_it->first])
            {
                break;
            }

            x = x - a[map_it->first];

            if( x > b[map_it->first])
            {
                number_of_dead++;
                a[map_it->first] = NO_PATIENT;
                b[map_it->first] = NO_PATIENT;
            }
            else
            {
                new_map.insert(pair<unsigned int, unsigned int>(map_it->first,map_it->first));
            }
            
            alive_patients_idx++;
        }

        new_map.insert(map_it,map_alive_patients.end());
        map_alive_patients.clear();
        map_alive_patients = new_map;

        number_of_dont_receive = map_size - alive_patients_idx;

        str_result = to_string(number_of_dead) + " " + to_string(number_of_dont_receive);

        return str_result;
    }

    void Initialize()
    {
        for(unsigned int i = 0; i < n; i++)
        {
            cin>>a[i];
            cin>>b[i];
            map_alive_patients.insert(pair<unsigned int, unsigned int>(i,i));
        }
    }

    void SetPatient(unsigned long long a, unsigned long long b, int c)
    {
        if( this->a[c-1] == NO_PATIENT)
        {
            map_alive_patients.insert(pair<unsigned int,unsigned int>(c-1,c-1));
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
    map<unsigned int,unsigned int> map_alive_patients;
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