#include <algorithm>
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i];

  std::vector<std::vector<long long> > dp(n, std::vector<long long>(m + 2));
  if (x[0] == 0) {
    std::fill(dp[0].begin() + 1, dp[0].end() - 1, 1);
  } else {
    dp[0][x[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (x[i] == 0) {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
      } else if (x[i] == j) {
        dp[i][x[i]] = (dp[i - 1][x[i] - 1] + dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) % MOD;
      }
    }
  }

  long long res = 0;
  for (int i = 1; i <= m; ++i) {
    res += dp[n - 1][i];
    res %= MOD;
  }

  std::cout << res << std::endl;

  return 0;
}