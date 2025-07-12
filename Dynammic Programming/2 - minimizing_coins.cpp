#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main()
{
  long long n, x;
  std::cin >> n >> x;
  std::vector<long long> coins(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> coins[i];

  std::vector<long long> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= x; ++i) {
    for (const auto& c : coins) {
      if (i - c >= 0 && dp[i - c] != INT_MAX) dp[i] = std::min(dp[i], dp[i - c] + 1);
    }
  }

  std::cout << (dp[x] == INT_MAX ? -1 : dp[x]) << std::endl;

  return 0;
}