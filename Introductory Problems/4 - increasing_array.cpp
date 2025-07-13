#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<long long> ivec(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> ivec[i];

  long long res = 0;
  for (int i = 1; i < n; ++i) {
    if (ivec[i] < ivec[i - 1]) {
      res += (ivec[i - 1] - ivec[i]);
      ivec[i] = ivec[i - 1];
    }
  }

  std::cout << res << std::endl;

  return 0;
}