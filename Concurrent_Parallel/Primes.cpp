/*!   \mainpage Prime numbers and their twins - CONCURRENT and/or PARALLEL
      \author Theodora Tataru, Student No: C00231174\n  
      \date 25 January 2020 
      \copyright  License: GNU Affero General Public License v3.0 
      \section Abstract class
      \subsection Describing the functions for the prime class
*/
#include "Primes.h"
#include <iostream>
#include <omp.h>

/*! \fn Primes::~Primes() = default
    \brief The destructor of the class
*/
Primes::~Primes() = default;

/*! \fn bool Primes::isPrime(int n)
    \param n The numbers that needs to be checked if is prime or not
    \brief A method checks if the number given as parameter is prime or not.
*/
bool Primes::isPrime(int n)
{
    number = n;
    int half = number/2;
    #pragma omp simd parallel for reduction(+:isPrime)
    for(int i = 2; i < half; i++)
    {
        count = 0;
        if(number%i==0)
        {
            return false;
        }
    }
    std::cout << number << " is prime" << std::endl;
    return true;
}

/*! \fn void Primes::numbersPrimeLessThen(int N)
    \param N The number that represents the upper limit of checking prime numbers
    \brief Method that returns all the prime numbers less then N, and all the twin prime numbers less then N
*/
void Primes::numbersPrimeLessThen(int N)
{
    int thisPrime = 0;
    int prevPrime = 0;
    #pragma omp simd parallel for reduction(+:numbersPrimeLessThen)
    for(int i = N; i >=2; i--)
    {
        if(isPrime(i))
        {
            prevPrime = thisPrime;
            thisPrime = i;
            twins(prevPrime, thisPrime);
        }
    }
}

/*! \fn void Primes::twins(int firstPrime, int secondPrime)
    \param int firstPrime
    \param int secondPrime
    \brief Method checks is 2 prime numbers are twins
*/
void Primes::twins(int firstPrime, int secondPrime)
{
    if(firstPrime-secondPrime == 2)
    {
        std::cout << "!!! --- Twins: " << firstPrime << " and " << secondPrime << std::endl;
    }
}