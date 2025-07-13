#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <unordered_map>

int main()
{
  int n, k;
  std::cin >> n >> k;
  std::vector<int> ivec(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> ivec[i];
  std::unordered_map<int, int> mp;
  std::vector<int> window(n - k + 1);

  for (int i = 0; i < k; ++i) {
    mp[ivec[i]]++;
  }
  window[0] = mp.size();

  for (int i = k; i < n; ++i) {
    int pre = ivec[i - k];
    int suf = ivec[i];
    mp[pre]--;
    if (mp[pre] == 0) {
      mp.erase(pre);
    }
    mp[suf]++;
    window[i - k + 1] = mp.size();
  }

  std::ostream_iterator<int> o_iter(std::cout, " ");
  std::copy(window.begin(), window.end(), o_iter);
  std::cout << std::endl;

  return 0;
}