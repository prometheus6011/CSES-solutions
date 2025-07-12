#include <iostream>

int main()
{
  long long n;
  std::cin >> n;

  long long s = 0;
  for (int i = 0; i < n - 1; ++i) {
    int t;
    std::cin >> t;
    s += t;
  }

  std::cout << ((n * (n + 1)) / 2) - s << std::endl;

  return 0;
}