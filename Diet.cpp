#include<iostream>
#include<list>

using namespace std;

#define DEBUG_LOG 0

class Diet{
public:
    Diet(int n) : number_of_dead(0), number_of_dont_receive(0),n(n)
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

        for(i = 0; i < n; i++)
        {
            if( a[i] == NO_PATIENT)
            {
                continue;
            }

            if( x < a[i])
            {
                number_of_dont_receive++;
                break;
            }

            x = x - a[i];

            if( x > b[i])
            {
                number_of_dead++;
                a[i] = NO_PATIENT;
                b[i] = NO_PATIENT;
            }
        }

        for( int j = i+1 ; j < n; j++)
        {
            if( a[j] == NO_PATIENT )
            {
                continue;
            }

            number_of_dont_receive++;
        }

        str_result = to_string(number_of_dead) + " " + to_string(number_of_dont_receive);

        return str_result;
    }

    void Initialize()
    {
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            cin>>b[i];
        }
    }

    void SetPatient(unsigned long long a, unsigned long long b, int c)
    {
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
    int number_of_dead;
    int number_of_dont_receive;
    unsigned long long *a;
    unsigned long long *b;
    int n;
};

int main()
{
    int n = 0;

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

    int q = 0;

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