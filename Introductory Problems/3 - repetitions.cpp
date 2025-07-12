#include <iostream>
#include <string>
#include <climits>

int main()
{
  std::string s;
  std::cin >> s;

  int res = INT_MIN;
  int i = 0;
  while (i < s.size()) {
    int curr_count = 0;
    int j = i;
    while (j < s.size() && s[i] == s[j]) {
      ++curr_count;
      ++j;
    }
    res = std::max(res, curr_count);
    i = j;
  }

  std::cout << res << std::endl;

  return 0;
}