#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<long long> coins(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> coins[i];

  std::vector<long long> dp(x + 1);
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (const auto& c : coins) {
      if (i - c >= 0) {
        dp[i] += dp[i - c];
        dp[i] %= MOD;
      }
    }
  }

  std::cout << dp[x] % MOD << std::endl;
  return 0;
}