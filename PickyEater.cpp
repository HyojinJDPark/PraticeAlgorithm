#include<iostream>

int main()
{
    int X = 0;
    int Y = 0;

    std::cin>>X;
    std::cin>>Y;

    if(X < 1 || X > 10 || Y < 1 || Y > 10)
    {
        std::cout<<"0"<<std::endl;
        return 0;
    }

    if(X >= Y)
    {
        std::cout<<"1"<<std::endl;
    }
    else
    {
        std::cout<<"0"<<std::endl;
    }
    
    return 0;
}