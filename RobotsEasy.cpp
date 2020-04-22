#include <iostream>
#include <cmath>
#include <list>

using namespace std;

class Robot
{
public:
    Robot() : target_c(0),target_r(0){}
    
    void FindTarget(int current_r, int current_c, unsigned char (*crossed_cell)[2])
    {
        if( current_c <= 6 )
        {
            target_r = 3;
            target_c = 3;
        }
        else
        {
            target_r = 3;
            target_c = 10;
        }
    }

    void FindPath(int current_r, int current_c, unsigned char (*blocked_cell)[2])
    {
        int move_r = current_r;
        int move_c = current_c;
        char up_down_left_right[4] = {'U','D','L','R'};
        list<char> list_path;
        int n = 0;

        while(1)
        {
            if(( move_r == 3 && move_c == 3 ) ||
                ( move_r == 3 && move_c ==10 ) ||
                ( move_r == 10 && move_c == 3 ) ||
                ( move_r == 10 && move_c == 10 ))
            {
                cout<<n<<endl;
                for(list<char>::iterator it = list_path.begin(); it != list_path.end(); it++)
                {
                    cout<<*it;
                }
                cout<<endl;
                break;
            }

            const unsigned char U = 0;
            const unsigned char D = 1;
            const unsigned char L = 2;
            const unsigned char R = 3;

            //Raw

            if( move_r != target_r && move_c != 2 && move_c != 11 && move_c != 6 && move_c != 7)
            {
                if( move_r < target_r )
                {
                    move_r++;
                    list_path.push_back(up_down_left_right[D]);
                    n++;
                }
                
                if( move_r > target_r )
                {
                    move_r--;
                    list_path.push_back(up_down_left_right[U]);
                    n++;
                }

                continue;
            }
            
            //Column
            if( move_c < target_c )
            {
                move_c++;
                list_path.push_back(up_down_left_right[R]);
                n++;
            }
            
            if ( move_c > target_c )
            {
                move_c--;
                list_path.push_back(up_down_left_right[L]);
                n++;
            }
        }
    }

private:
    int target_r;
    int target_c;
};

int main()
{
    unsigned char blocked_cell[10][2] = {6,6,6,7,7,6,7,7,9,2,9,3,9,10,9,11,10,2,10,11};
    unsigned char crossed_cell[4][2] = {3,3,3,10,10,3,10,10};

/* to check right input
    for(int i = 0; i < 10 ; i++)
    {
        if( i < 4)
        {
            cout<<"Blocked cell ("<<(int)blocked_cell[i][0]<<","<<(int)blocked_cell[i][1]<<")"<<endl;
            cout<<"crossed cell ("<<(int)crossed_cell[i][0]<<","<<(int)crossed_cell[i][1]<<")"<<endl;
        }
        else
        {
            cout<<"Blocked cell ("<<(int)blocked_cell[i][0]<<","<<(int)blocked_cell[i][1]<<")"<<endl;
        }
        
    }
*/
    {
        int L = 0;

        cin>>L;

        if(L < 1 || L > 134) return 0;
        
        int number_of_rc = 0;
        int *r = new int[L];
        int *c = new int[L];

        while(1)
        {
            if(number_of_rc == L ) break;

            cin >> r[number_of_rc];
            cin >> c[number_of_rc];

            if( r[number_of_rc] < 1 || r[number_of_rc] > 12 ) return 0;
            if( c[number_of_rc] < 1 || c[number_of_rc] > 12 ) return 0;

            number_of_rc++;
        }

/*      to check input data set
        for(int i = 0; i < L ; i++ )
        {
            cout<<"data set ("<<r[i]<<", "<<c[i]<<")"<<endl;
        }
*/
        for( unsigned char i = 0; i < L ; i++ )
        {
            Robot robot_inst;
            robot_inst.FindTarget(r[i],c[i],crossed_cell);
            robot_inst.FindPath(r[i],c[i],blocked_cell);    
        }
    }

    return 0;
}