# fast-prime-factorization
Initially a learning project of mine that I made to start my C++ learning, but I ended up hyper-optimizing it.
Supports numbers up to 2^64 - 1 (uint_64t's limit), with calculation for the largest prime that fits in uint_64t - 18446744073709551557 - taking 3.8 seconds on average to factor (aka find out that it's prime) on my laptop (with an i5-12450H).

Compilation:
```bash
clang++ primeFactorization.cpp -o factors.exe -o2
```

I could've probably searched for optimizations of the compiler such as using a different one or passing different arguments, but the above provided command is what led to the 'advertised' performance.

Optimizations that I have done:
* First divide the number by 2 and 3 as many times as possible
* Instead of checking if n % 2 == 0, check n & 1 == 0, which is a bitwise operation that is quicker (by like a CPU cycle or something)
* Bitshift by 1 to the right instead of dividing by 2
* Take the square root of the number after the divisions by 2 and 3
* Take the square root out of the number shifted to the right by 6, then shift the square root by 3 to the left
* Then utilize the fact that every prime higher than 3 can be written in the form 6k±1
* If n > 1 after looping through numbers up to √n then append n (less of an optimization and more of how this works)
