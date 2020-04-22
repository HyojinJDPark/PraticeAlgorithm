#include<iostream>
#include<list>
#include<time.h>
#include<math.h>

bool isPrime(int num);

#define TIME 0

int main()
{
    int n = 0;

    std::cin>>n;

#if TIME
    clock_t t;
    t = clock();
#endif
    if( n < 2 || n > 10000000)
    {
        std::cout<<"-1"<<std::endl;
        return 0;
    }
/*
    int i = 0;

    for(i = 2; i <= n/2; i++)
    {
        if(isPrime(i) && isPrime(n-i))
        {
            std::cout<<i<<" "<<(n-i)<<std::endl;
            return 0;
        }
    }
*/
    bool *primes = new bool[n+1];

    for(int i = 2; i <= n; i++)
    {
        primes[i] = true;
    }

    for(int i = 2; i * i <= n; i++)
    {
        if(primes[i])
        {
            for(int j = i*i; j<=n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    for(int i = 2; i <= n/2; i++)
    {
        if(primes[i] && primes[n-i])
        {
            std::cout<<i<<" "<<(n-i)<<std::endl;
            return 0;
        }
    }

    //find prime number
#if TIME
    t = clock() - t;
    std::cout<<"time : "<<t/1000<<std::endl;
#endif

    std::cout<<"-1"<<std::endl;

    return 0;
}

bool isPrime(int num)
{
    using namespace std;

    static list<int> prime_list;

    //if the num is divided by prime number, that means it is not prime.
    for(list<int>::iterator it = prime_list.begin(); it != prime_list.end() ; it++)
    {
        if((num != *it) && (num % *it == 0))
        {
            return false;
        }
    }

    int i = 0;

    for(i = prime_list.size() == 0 ? 2:prime_list.back() + 1; i <= sqrt(num); i ++ )
    {
        if((num % i == 0))
        {
            return false;
        }
    }

    prime_list.push_back(i);

    return true;
}