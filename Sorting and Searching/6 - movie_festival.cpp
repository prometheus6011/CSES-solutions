#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > intervals;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    intervals.emplace_back(a, b);
  }

  std::sort(intervals.begin(), intervals.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
  });

  int res = 0;
  int curr_time = 0;
  for (int i = 0; i < n; ++i) {
    if (intervals[i].first >= curr_time) {
      ++res;
      curr_time = intervals[i].second;
    }
  }

  std::cout << res << std::endl;

  return 0;
}