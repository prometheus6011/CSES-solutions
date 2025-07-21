#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > times(n);
  for (int i = 0; i < n; ++i) {
    int start, end;
    std::cin >> start >> end;
    times.emplace_back(start, 1);
    times.emplace_back(end, -1);
  }

  std::sort(times.begin(), times.end());

  int curr = 0;
  int res = 0;
  for (const auto& t : times) {
    curr += t.second;
    res = std::max(res, curr);
  }

  std::cout << res << std::endl;

  return 0;
}