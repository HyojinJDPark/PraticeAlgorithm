#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class Fighter
{
private:

public:
    Fighter(int n, int x, int y, short a,unsigned char r) : n(n),x(x),y(y),a(a),r(r),pi(3.1415926535897){}

    void print()
    {
        cout<<x<<" "<<y<<" "<<" "<<a<<" "<<(int)r<<endl;
        cout<<"y = "<< tan(a-r) <<"(x - "<<x<<") + "<<y<<endl;
        cout<<"y = "<< tan(a+r) <<"(x - "<<x<<") + "<<y<<endl;
    }

    bool IsRange(int x, int y)
    {
        if( y >= tan(a-r) * (x - this->x ) + this->y && y <= tan( a+r ) * (x - this->x ) + this->y)
        {
            return true;
        } 
        return false; 
    }

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }

    int getNth()
    {
        return this->n;
    }

private:
    short n;
    int x;
    int y;
    short a;
    unsigned char r;
    const float pi;
};

int main()
{
    int N = 0;

    cin>>N;

    if(N < 1 || N > 3000) return 0;
    
    list<Fighter> fighter_list;
    list<short> number;

    for(short i = 0; i < N;i++)
    {
        int x,y,a,r = 0;

        cin >> x;
        cin >> y;
        cin >> a;
        cin >> r;

        if( x < -1000000 || x > 1000000) return 0;
        if( y < -1000000 || y > 1000000) return 0;
        if( a < 0 || a > 359) return 0;
        if( r < 0 || r > 89 ) return 0;

        fighter_list.push_back(Fighter(i+1,x,y,(short)a,(unsigned char)r));
    }

#define DATA_CHECK 1

#if DATA_CHECK
    //to check data set
      for(list<Fighter>::iterator it = fighter_list.begin(); it != fighter_list.end(); it++)
        {
            it->print();
        }
#endif

/*
    while(1)
    {
        size_t size_list = fighter_list.size();

        if(fighter_list.size() == 1)
        {
            cout<<fighter_list.front().getNth()<<endl;
            break;
        }

        for(list<Fighter>::iterator it1 = fighter_list.begin(); it1 != fighter_list.end(); it1++)
        {
            list<Fighter>::iterator it;

            for(it = fighter_list.begin(); it != fighter_list.end(); it++)
            {
                if(it1->getX() == it->getX() && it1->getY() == it->getY()) continue; // no need to compare same value

                if( it->IsRange(it1->getX(), it1->getY()) ) break;
            }

            if(it == fighter_list.end())
            {
                number.push_back(static_cast<short>(it1->getNth()));
                fighter_list.erase(it1);
            }
        }

        if(size_list == fighter_list.size())
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    for(list<short>::iterator it = number.begin(); it != number.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
*/  
    return 0;
}