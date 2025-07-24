#include <climits>
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<int> coins(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> coins[i];
  std::vector<long long> dp(x + 1);
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (j - coins[i] >= 0) {
        dp[j] += dp[j - coins[i]];
        dp[j] %= MOD;
      }
    }
  }

  std::cout << dp[x] % MOD << std::endl;

  return 0;
}