#include <iostream>
#include <vector>

std::vector<long long> generator(long long n, long long x, long long a, long long b, long long c)
{
  std::vector<long long> ivec(n, 0);
  ivec[0] = x;
  for (long long i = 1; i < n; ++i) {
    ivec[i] = (a * ivec[i - 1] + b) % c;
  }
  return ivec;
}

int main()
{
  int n, k;
  std::cin >> n >> k;
  int x, a, b, c;
  std::cin >> x >> a >> b >> c;
  std::vector<long long> ivec = generator(n, x, a, b, c);

  long long curr_sum = 0;
  for (int i = 0; i < k; ++i) {
    curr_sum += ivec[i];
  }

  int j = 1;
  long long res = curr_sum;
  for (int i = k; i < n; ++i) {
    int pre = ivec[j - 1];
    int suf = ivec[i];
    curr_sum -= pre;
    curr_sum += suf;
    res ^= curr_sum;
    ++j;
  }

  std::cout << res << std::endl;

  return 0;
}