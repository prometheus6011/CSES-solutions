#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<long long> x(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  
  long long curr_sum = x[0];
  long long max_sum = x[0];

  for (int i = 1; i < n; ++i) {
    curr_sum = std::max(curr_sum + x[i], x[i]);
    max_sum = std::max(max_sum, curr_sum);
  }

  std::cout << max_sum << std::endl;

  return 0;
}