/*!   \mainpage Prime Numbers and Prime Twin Numbers
      \author Theodora Tataru, Student No: C00231174\n  
      \date 26 January 2020 
      \copyright  License: GNU Affero General Public License v3.0 
      \section Abstract
      \subsection The task is to write a parallel program that counts the number of primes less than n for any number n and also finds and lists all twin primes less than n. The code should run on linux.
*/
#include <iostream>
#include <chrono>
#include <iostream>
#include <omp.h>

/*! \fn void isPrime(int N)
    \param n The number that represents the upper limit of checking prime numbers
    \brief Method that returns if a number is prime or not
*/
bool isPrime(int n)
{
    int number = n;
    int half = number/2;
    if(number <= 1) return false;
    if(number <= 3) return true;
    if(number%3 == 0) return false;
    if(number%2 == 0) return false;
    for(int i = 5; i<=half; i++)
    {
        if(number%i==0)
        {
            return false;
        }
    }
    return true;
}


/*! \fn void numbersPrimeLessThen(int N)
    \param N The number that represents the upper limit of checking prime numbers
    \brief Method that returns all the prime numbers less than N
*/
void numbersPrimeLessThen(int N)
{
    int count = 0;
    #pragma omp parallel for num_threads(1) shared(count)
    for(int number = 2; number <= N; number++) 
    {
        //std::cout << "Thread ::numbersPrimeLessThen: " <<  omp_get_thread_num() << std::endl;
        if(isPrime(number))
        {
            #pragma omp atomic
            count++;
        }
    }
    printf("\nNumber of primes less than %d: %d\n", N, count);
}

/*! \fn void Primes::twins(int N)
    \param N The number that represents the upper limit of checking for prime twins
    \brief Method checks if 2 prime numbers are twins from the vector of primes
*/
void twins(int N)
{
    std::cout << "Twins: " << std::endl;
    int sum = 0;
    //#pragma omp parallel for num_threads(4) 
    for(int i = 2; i <= N; i++)
    {
        if(isPrime(i) && isPrime(i+2))
        {
            printf(" (%d,%d)",i,i+2); 
            //#pragma omp atomic
            sum++;
        }
    }
    printf("\nNumbers of prime twins: %d", sum);
}

int main(int argc, char *argv[])
{
    char *numberFromCommandLine = argv[1];
    int number = atoi(numberFromCommandLine);

    auto startTime = std::chrono::high_resolution_clock::now();
    twins(number);
    numbersPrimeLessThen(number);
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( endTime - startTime ).count();
    std::cout << std::endl;
    std::cout << "Parallel execution for N = " << number << ": " << duration << " milliseconds";

    return 0;
}
