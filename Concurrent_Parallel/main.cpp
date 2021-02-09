/*!   \mainpage Prime Numbers and Prime Twin Numbers
      \author Theodora Tataru, Student No: C00231174\n  
      \date 26 January 2020 
      \copyright  License: GNU Affero General Public License v3.0 
      \section Abstract
      \subsection The task is to write a parallel program that counts the number of primes less than n for any number n and also finds and lists all twin primes less than n. The code should run on linux.
*/
#include "Primes.h"
#include <iostream>
#include <chrono>

int main(void)
{
    Primes p = Primes();
    int number = 0;
    /*std::cout << "(Insert -1 to stop)" << std::endl;
    while(number != -1)
    {   
        std::cout << "Please insert a number: ";
        std::cin >> number;
        p.isPrime(number);
        std:: cout << std::endl;
    }*/
    std::cout << "Please insert a number: ";
    std::cin >> number;

    auto startTime = std::chrono::high_resolution_clock::now();
    p.numbersPrimeLessThen(number);
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( endTime - startTime ).count();
    std::cout << std::endl;
    std::cout << "Parallel execution for N = " << number << ": " << duration << " milliseconds" << std::endl;

    return 0;
}
