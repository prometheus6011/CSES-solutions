#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<long long> x(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> x[i];

  std::sort(x.begin(), x.end());
  long long ans = 1;
  for (int i : x) {
    if (ans < i) {
      break;
    }
    ans += i;
  }
  std::cout << ans << std::endl;

  return 0;
}