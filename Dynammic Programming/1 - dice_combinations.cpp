#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main()
{
  int n;
  std::cin >> n;

  std::vector<long long> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6 && (i - j) >= 0; ++j) {
      dp[i] += (dp[i - j] % MOD);
    }
  }

  std::cout << dp[n] % MOD << std::endl;

  return 0;
}