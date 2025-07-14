#include <algorithm>
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main()
{
  int n;
  std::cin >> n;

  std::vector<std::vector<char> > grid(n, std::vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) std::cin >> grid[i][j];
  }

  std::vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    if (grid[0][i] == '*') {
      std::fill(dp.begin() + i, dp.end(), 0);
      break;
    }
    else dp[i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    std::vector<int> temp(n);
    temp[0] = grid[i][0] == '*' ? 0 : dp[0];
    for (int j = 1; j < n; ++j) {
      if (grid[i][j] == '*') {
        temp[j] = 0;
      } else {
        temp[j] = (temp[j - 1] + dp[j]) % MOD;
      }
    }
    dp = temp;
  }

  std::cout << dp[n - 1] << std::endl;

  return 0;
}