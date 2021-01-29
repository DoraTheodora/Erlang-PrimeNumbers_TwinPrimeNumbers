#include "Primes.h"
#include <iostream>

Primes::~Primes() = default;

bool Primes::isPrime(int n)
{
    number = n;
    int half = number/2;
    for(int i = 2; i < half; i++)
    {
        if(number%i==0)
        {
            return false;
        }
    }
    std::cout << number << " is prime" << std::endl;
    return true;
}

void Primes::numbersPrimeLessThen(int N)
{
    int position = 0;
    int checkTwins[2] = {0,0};
    int thisPrime = 0;
    int prevPrime = 0;
    for(int i = N; i >=2; i--)
    {
        if(isPrime(i))
        {
            prevPrime = thisPrime;
            thisPrime = i;
            checkTwins[position] = prevPrime;
            checkTwins[position+1] = thisPrime;
            twins(checkTwins);
        }
    }
}

void Primes::twins(int twin[])
{
    //std::cout << "!!! --- Check Twins: " << twin[0] << " and " << twin[1] << std::endl;
    if(twin[0]-twin[1] == 2)
    {
        std::cout << "!!! --- Twins: " << twin[0] << " and " << twin[1] << std::endl;
    }
}