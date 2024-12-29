#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
uint64_t q_multiplySix(uint64_t n)
{
  return (n << 2) + (n << 1);
}

vector<uint64_t> calculateFactors(uint64_t n)
{
  auto start = chrono::high_resolution_clock::now();
  vector<uint64_t> factors;

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
  uint64_t sqrtN = uint64_t(sqrtl(n >> 6)) << 3; // 8 * sqrt(n / 64)
  for (uint64_t i = 1; i <= sqrtN; i++) // 6k +/- 1
  {
    if (n == 1) break;
    uint64_t factor = q_multiplySix(i) - 1; // 6k - 1
    while (n % factor == 0)
    {
      factors.push_back(factor);
      n /= factor;
    }
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
  uint64_t n;
  cout << "Enter a number: ";
  cin >> n;
  vector<uint64_t> factors = calculateFactors(n);
  cout << "Factors: ";
  for (uint64_t factor : factors)
  {
    cout << factor << " ";
  }
  cout << "\n";
  return 0;
}