#include <iostream>

const int MOD = 1e9 + 7;

int main()
{
  int n;
  std::cin >> n;
  unsigned long long res = 1;
  
  for (int i = 0; i < n; ++i) {
    res *= 2;
    res %= MOD;
  }

  std::cout << res << std::endl;

  return 0;
}