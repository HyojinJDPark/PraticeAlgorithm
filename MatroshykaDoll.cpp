#include<iostream>

int main()
{
    int number_of_dolls = 0, s = 0,x = 0;

    std::cin>>s;
    std::cin>>x;

    if(s < 1 || s > 1000000000) return 0;
    if(x < 2 || x > 1000000000) return 0;

    if( s < x )
    {
        std::cout<<1<<std::endl;
        return 0;
    }

    while(1)
    {
        s = s/x;

        number_of_dolls++;

        if( s < 1 ) break;
    }

    std::cout<<number_of_dolls<<std::endl;

    return 0;
}