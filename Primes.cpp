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
            std::cout << number << " is not prime" << std::endl;
            return false;
        }
    }
    std::cout << number << " is prime" << std::endl;
    return true;
}