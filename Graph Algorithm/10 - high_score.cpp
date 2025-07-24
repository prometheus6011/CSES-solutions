#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <tuple>

void bellman_ford(const std::vector<std::tuple<long long, long long, long long> >& edges, int n)
{
  std::vector<long long> distance(n, LLONG_MIN);
  distance[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (const auto& [a, b, w] : edges) {
      if (distance[a] != LLONG_MIN) {
        distance[b] = std::max(distance[b], distance[a] + w);
      }
    }
  }

  std::vector<bool> cycle_detected(n, false);
  for (int i = 0; i < n; ++i) {
    for (const auto& [a, b, w] : edges) {
      if (distance[a] != LLONG_MIN && distance[b] < distance[a] + w) {
        cycle_detected[b] = true;
      }
      if (cycle_detected[a]) cycle_detected[b] = true;
    }
  }

  if (cycle_detected[n - 1]) {
    std::cout << -1 << std::endl;
    return;
  }
  std::cout << distance[n - 1] << std::endl;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::tuple<long long, long long, long long> > edges;
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    std::cin >> a >> b >> w;
    --a, --b;
    edges.emplace_back(a, b, w);
  }
  bellman_ford(edges, n);
  return 0;
}