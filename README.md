# fast-prime-factorization
Initially a learning project of mine that I made to start my C++ learning, but I ended up hyper-optimizing it.
Supports numbers up to 2^64 - 1 (uint_64t's limit), with calculation for the largest prime that fits in uint_64t - 18446744073709551557 - taking 3.8 seconds on average on my laptop (i5-12450H).

Compilation:
```bash
clang++ primeFactorization.cpp -o factors.exe -o2
```

I could've probably searched for optimizations of the compiler such as using a different one or passing different arguments, but the above provided command is what led to the 'advertised' performance.

Optimizations:

