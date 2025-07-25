#include <iostream>
#include <ostream>
#include <vector>
#include <utility>

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<std::pair<int, int> > hs(n);
  for (int i = 0; i < n; ++i) std::cin >> hs[i].first;
  for (int i = 0; i < n; ++i) std::cin >> hs[i].second;

  std::vector<int> dp(x + 1);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = x; j >= hs[i].first; --j) {
      dp[j] = std::max(dp[j], hs[i].second + dp[j - hs[i].first]);
    }
  }

  std::cout << dp[x] << std::endl;

  return 0;
}