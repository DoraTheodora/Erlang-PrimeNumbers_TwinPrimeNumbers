/*!   \mainpage Prime Numbers and Prime Twin Numbers
      \author Theodora Tataru, Student No: C00231174\n  
      \date 26 January 2020 
      \copyright  License: GNU Affero General Public License v3.0 
      \section Abstract
      \subsection The task is to write a parallel program that counts the number of primes less than n for any number n and also finds and lists all twin primes less than n. The code should run on linux.
*/
#include <iostream>
#include <chrono>
#include <omp.h>

void example()
{
    #pragma omp parallel for num_threads(4) collapse(2)
    for(int i=0; i< 5; i++) 
    {
        for (int j=0; j< 5; j++) 
        {
            printf("i = %d, j= %d, threadId = %d \n", i, j, omp_get_thread_num());
        }
    }
} 


int numPrimeNumbers(int n)
{
    int i;
    int j;
    int prime;
    int total = 0;


    # pragma omp critical 
    # pragma parallel omp for reduction ( + : total )  num_threads(4) private ( n, prime, i, j) 
    for ( i = 2; i <= n; i++ )
    {
        prime = 1;

        for ( j = 2; j < i; j++ )
        {
            
            std::cout << "Thread: " << omp_get_thread_num() << " I: " << i << " J:" << j << std::endl;
            if ( i % j == 0 )
            {
                //std::cout << "hello from thread: " << omp_get_thread_num() << "\n" << std::endl;
                prime = 0;
                break;
            }
        }
        total = total + prime;
    }

    return total;
} 


int main(void)
{
    auto startTime = std::chrono::high_resolution_clock::now();
    //int s = numPrimeNumbers(100);
    example();
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( endTime - startTime ).count();
    std::cout << std::endl;
    //std::cout << "Sum = " << s << std::endl;
    std::cout << "Execution: " << duration << " milliseconds" << std::endl;

    return 0;
}
