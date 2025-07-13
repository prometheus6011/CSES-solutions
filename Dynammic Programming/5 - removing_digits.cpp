#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> get_digits(int n)
{
  std::vector<int> digits;
  while (n != 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
  return digits;
}

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (const auto& d : get_digits(i)) {
      if (i - d >= 0 && dp[i - d] != INT_MAX) {
        dp[i] = std::min(dp[i], dp[i - d] + 1);
      }
    }
  }

  std::cout << dp[n] << std::endl;

  return 0;
}