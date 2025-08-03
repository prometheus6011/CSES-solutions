#include <iostream>
#include <set>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int x, n;
  std::cin >> x >> n;

  std::set<int> st{0, x};
  std::multiset<int> ms{x};

  for (int i = 0; i < n; ++i) {
    int p;
    std::cin >> p;
    auto iter1 = st.lower_bound(p);
    auto iter2 = iter1;
    --iter2;

    ms.erase(ms.lower_bound(*iter1 - *iter2));
    ms.insert(p - *iter2);
    ms.insert(*iter1 - p);
    st.insert(p);

    std::cout << *(--(ms.end())) << " ";
  }
  std::cout << std::endl;

  return 0;
}