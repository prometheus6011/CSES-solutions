#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <algorithm>

int main()
{
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> a(n);
  std::vector<int> b(m);

  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int res = 0;
  int i = 0;
  int j = 0;

  while (i < a.size() && j < b.size()) {
    if (std::abs(a[i] - b[j]) <= k) {
      ++res, ++i, ++j;
    } else if (a[i] - b[j] > k) {
      ++j;
    } else {
      ++i;
    }
  }

  std::cout << res << std::endl;

  return 0;
}