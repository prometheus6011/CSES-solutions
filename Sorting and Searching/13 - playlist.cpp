#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <set>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> k(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> k[i];
  std::set<int> seen;

  int max_size = INT_MIN;
  int left = 0;
  for (int right = 0; right < n; ++right) {
    while (left <= n && seen.find(k[right]) != seen.end()) {
      seen.erase(k[left]);
      ++left;
    }
    seen.insert(k[right]);
    max_size = std::max(max_size, right - left + 1);
  }

  std::cout << max_size << std::endl;

  return 0;
}