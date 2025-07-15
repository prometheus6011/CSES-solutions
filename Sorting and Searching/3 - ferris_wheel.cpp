#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<int> p(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> p[i];

  std::sort(p.begin(), p.end());

  int res = 0;
  int left = 0, right = n - 1;

  while (left <= right) {
    int sum = p[left] + p[right];
    if (sum <= x) {
      ++res, ++left, --right;
    } else {
      ++res, --right;
    }
  }

  std::cout << res << std::endl;

  return 0;
}