# Erlang-PrimeNumbers_TwinPrimeNumbers

### Concurrency Project
<h6>Developer: Theodora Tataru </h6>
<h6>Tutor: Joseph Kehoe </h6>
<h6>Institute of Technology Carlow, 2021 </h6>
### Prime Numbers
There are an infinite number of prime numbers. Amongst the primes there are what are known as twin primes.

A twin prime is a prime number that is either 2 less or 2 more than another prime number—for example, either member of the twin prime pair: ``` (41, 43)```. In other words, a twin prime is a prime that has a prime gap of two. Sometimes the term twin prime is used for a pair of twin primes; an alternative name for this is prime twin or prime pair.

It is (currently) unknown whether there are an infinite number of twin primes. 

<b>Examples include: </b> 
```code
(3, 5), (5, 7), (11, 13), (17, 19), (29, 31), (41,43),... 
```

The task is to write a parallel program that counts the number of primes less than n for any number n and also finds and lists all twin primes less than n. The code should run on linux.

<b>Example output after running your code with n = 50 would be: </b>

```code
>
primeTwinCount 50

Total number of primes: 15

Twin Primes: 3, 5, 7, 11, 13, 17, 19, 29, 31, 41, 43

>
```

<b>The project consists of: </b>

- Source Code 

Full source code including README, full installation instructions, Makefile and Doxygen Configuration file;
 - Report 
 
 A short report on the approach you took to achieving maximum concurrency. This will contain:
    1. Pseudocode Outline of the algorithm illustrated with pseudocode;
    2. Speedup Results Both absolute speedup and relative speedup should be calculated
    3. Scalability Graph(s) showing the scalabiltiy of your code.
- The report does not need to be long. It must be concise and on point.
- The idea is that you learn how to measure code performance as well as write parallel code. There is plenty of scope for making the code efficient.
