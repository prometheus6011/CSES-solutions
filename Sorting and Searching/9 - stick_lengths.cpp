#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;
  std::vector<long long> p(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }

  std::sort(p.begin(), p.end());

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += std::abs(p[i] - p[p.size() / 2]);
  }

  std::cout << res << std::endl;

  return 0;
}