#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::tuple<int, int, long long> > edges(m);
  for (int i = 0; i < m; ++i) {
    long long a, b, c;
    std::cin >> a >> b >> c;
    --a, --b;
    edges.emplace_back(a, b, c);
  }

  std::vector<long long> dist(n, 0);
  std::vector<int> parent(n, -1);
  int candidate = -1;

  for (int i = 0; i < n; ++i) {
    candidate = -1;
    for (const auto& [a, b, c] : edges) {
      if (dist[a] + c < dist[b]) {
        dist[b] = dist[a] + c;
        parent[b] = a;
        candidate = b;
      }
    }
  }

  if (candidate == -1) {
    std::cout << "NO" << std::endl;
  } else {
    for (int i = 0; i < n; ++i) candidate = parent[candidate];
    std::vector<int> cycle;
    for (int i = candidate; ; i = parent[i]) {
      cycle.push_back(i);
      if (i == candidate && cycle.size() > 1) break;
    }
    std::reverse(cycle.begin(), cycle.end());
    std::cout << "YES" << std::endl;
    for (int i : cycle) {
      std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}