/*!   \mainpage Prime numbers and their twins
      \author Theodora Tataru, Student No: C00231174\n  
      \date 25 January 2020 
      \copyright  License: GNU Affero General Public License v3.0 
      \section Abstract class
      \subsection Describing the functions for the prime class
*/
class Primes
{
    int number;
    int count;
    #pragma omp parallel for reduction(+:pc)
    public: Primes()
    {
        number = 0;
        count = 0;
    }
    ~Primes();
    bool isPrime(int n);

    void numbersPrimeLessThen(int N);

    void twins(int firstPrime, int secondPrime);
};