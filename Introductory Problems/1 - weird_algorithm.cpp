#include <iostream>

int main()
{
  long long n;
  std::cin >> n;
  std::cout << n << ' ';
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    std::cout << n << ' ';
  }
  std::cout << std::endl;
  return 0;
}