#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main()
{
  int n = 0;
  char c;
  std::unordered_map<char, int> freq;
  while (std::cin >> c) {
    freq[c]++;
    ++n;
  }

  int num_odd = 0;
  char odd_char;
  for (const auto& [c, f] : freq) {
    if (f % 2 == 1) {
      ++num_odd;
      odd_char = c;
    }
  }

  if (num_odd >= 2) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  std::string half, middle;
  for (const auto& [c, f] : freq) {
    if (f % 2 == 1) middle = std::string(f, c);
    else half += std::string(f / 2, c);
  }

  std::string res = half + middle;
  std::reverse(half.begin(), half.end());
  res += half;

  std::cout << res << std::endl;

  return 0;
}