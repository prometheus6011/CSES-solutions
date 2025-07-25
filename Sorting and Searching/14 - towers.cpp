#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> k(n);
  for (int i = 0; i < n; ++i) std::cin >> k[i];

  std::deque<int> dq;
  for (int i = 0; i < n; ++i) {
    if (dq.empty() || k[i] >= dq.back()) {
      dq.push_back(k[i]);
    } else {
      auto iter = std::upper_bound(dq.begin(), dq.end(), k[i]);
      *iter = k[i];
    }
  }

  std::cout << dq.size() << std::endl;

  return 0;
}