#include <iostream>
#include <string>
#include <utility>
#include <set>

void permute(std::set<std::string>& res, std::string s, int curr_idx)
{
  if (curr_idx == s.size()) {
    res.insert(s);
    return;
  }
  for (int i = curr_idx; i < s.size(); ++i) {
    std::swap(s[curr_idx], s[i]);
    permute(res, s, curr_idx + 1);
    std::swap(s[curr_idx], s[i]);
  }
}

std::set<std::string> permutations(std::string s)
{
  std::set<std::string> res;
  permute(res, s, 0);
  return res;
}

int main()
{
  std::string s;
  std::cin >> s;
  std::set<std::string> res = permutations(s);
  std::cout << res.size() << std::endl;
  for (const auto& s : res) {
    std::cout << s << std::endl;
  }
  return 0;
}