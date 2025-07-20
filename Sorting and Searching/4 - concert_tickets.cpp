#include <iostream>
#include <set>

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::multiset<int> ms;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    ms.insert(a);
  }
  
  for (int i = 0; i < m; ++i) {
    int b;
    std::cin >> b;
    auto iter = ms.upper_bound(b);
    if (iter == ms.begin()) {
      std::cout << -1 << std::endl;
    } else {
      iter--;
      std::cout << *iter << std::endl;
      ms.erase(iter);
    }
  }

  return 0;
}