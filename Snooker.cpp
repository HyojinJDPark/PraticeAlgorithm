#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned int m,n,x0,x1,y0,y1,k = 0;
    bool bError = false;

    while(1)
    {
       scanf("%d",&m);
        if( m < 2 || m > 100 )
        {
            bError = true;
            break;
        }

        scanf("%d", &n);
        if( n < 2 || n > 100 )
        {
            bError = true;
            break;
        }

        scanf("%d", &x0 ) ;
        if( x0 > m)
        {
            bError = true;
            break;
        }

        scanf("%d", &x1 ) ;
        if( x1 > m)
        {
            bError = true;
            break;
        }

        scanf("%d", &y0 ) ;
        if( y0 > n )
        {
            bError = true;
            break;
        }

        scanf("%d", &y1 ) ;
        if( y1 > n )
        {
            bError = true;
            break;
        }

        scanf("%d", &k );
        if( k > 100 ) 
        {
            bError = true;
            break;
        }

        break;
    }

    if(bError)
    {
        cout<<"You type wrong value"<<endl;
        cout<<(int)m<<" "<<(int)n<<" "<<(int)x0<<" "<<(int)x1<<" "<<(int)y0<<" "<<(int)y1<<" "<<(int)k<<" "<<endl;
    }
    else
    {
        cout<<(int)m<<" "<<(int)n<<" "<<(int)x0<<" "<<(int)x1<<" "<<(int)y0<<" "<<(int)y1<<" "<<(int)k<<" "<<endl;
    }

    return 0;
}