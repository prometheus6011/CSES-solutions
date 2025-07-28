#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<long long> x(n, 0), pos(n + 1);
  for (int i = 0; i < n; ++i) { 
    std::cin >> x[i];
    pos[x[i]] = i;
  }

  int rounds = 1;
  for (int i = 1; i < n; ++i) {
    if (pos[i + 1] < pos[i]) {
      ++rounds;
    }
  }

  std::cout << rounds << std::endl;

  return 0;
}