#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> ivec(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> ivec[i];
  std::sort(ivec.begin(), ivec.end());

  int res = 1;
  for (int i = 1; i < ivec.size(); ++i) {
    if (ivec[i - 1] != ivec[i]) ++res;
  }

  std::cout << res << std::endl;

  return 0;
}