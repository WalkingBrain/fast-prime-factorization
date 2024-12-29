#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
unsigned long long q_multiplySix(unsigned long long n)
{
  return (n << 2) + (n << 1);
}

vector<unsigned long long> calculateFactors(unsigned long long n)
{
  auto start = chrono::high_resolution_clock::now();
  vector<unsigned long long> factors;

  while ((n & 1) == 0) // n % 2 == 0
  {
    factors.push_back(2);
    n = n >> 1; // n /= 2
  }
  while (n % 3 == 0)
  {
    factors.push_back(3);
    n /= 3;
  }
  unsigned long long sqrtN = q_multiplySix(sqrtl(n >> 5)); // 6 * sqrt(n / 32)
  for (unsigned long long i = 1; i <= sqrtN; i++) // 6k +/- 1
  {
    if (n == 1) break;
    unsigned long long factor = q_multiplySix(i) - 1; // 6k - 1
    while (n % factor == 0)
    {
      factors.push_back(factor);
      n /= factor;
    }
    if (n == 1) break;
    factor += 2; // 6k + 1
    while (n % factor == 0)
    {
      factors.push_back(factor);
      n /= factor;
    }
  }

  if (n > 1)
    factors.push_back(n);

  auto end = chrono::high_resolution_clock::now();
  auto duration = end - start;
  cout << "Time taken: " << chrono::duration_cast<chrono::nanoseconds>(duration).count() << " nanoseconds\n";
  return factors;
}

int main()
{
  unsigned long long n;
  cout << "Enter a number: ";
  cin >> n;
  vector<unsigned long long> factors = calculateFactors(n);
  cout << "Factors: ";
  for (unsigned long long factor : factors)
  {
    cout << factor << " ";
  }
  cout << "\n";
  return 0;
}