#include <iostream>
#include <vector>
#include <map>

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::map<int, int> complements;
  for (int i = 0; i < n; ++i) {
    int comp = x - a[i];
    if (complements.find(comp) != complements.end()) {
      std::cout << complements[comp] + 1 << " " << i + 1 << std::endl;
      return 0;
    }
    complements[a[i]] = i;
  }


  std::cout << "IMPOSSIBLE" << std::endl;

  return 0;
}