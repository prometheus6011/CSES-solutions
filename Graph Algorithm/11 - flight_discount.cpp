#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

std::vector<long long> dijkstras(const std::vector<std::vector<std::pair<long long, long long> > >& edges, int start)
{
  int n = edges.size();
  std::vector<bool> visited(n, false);
  std::vector<long long> distance(n, LLONG_MAX);
  distance[start] = 0;
  std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long> >, std::greater<std::pair<long long, long long> > > pq;
  pq.emplace(0, start);  // (distance, node)
  while (!pq.empty()) {
    int a = pq.top().second;
    pq.pop();
    if (visited[a]) continue;
    visited[a] = true;
    for (const auto& e : edges[a]) {
      int b = e.first;
      int w = e.second;
      if (distance[a] + w < distance[b]) {
        distance[b] = distance[a] + w;
        pq.emplace(distance[b], b);
      }
    } 
  }

  return distance;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<long long, long long> > > adj(n);
  std::vector<std::vector<std::pair<long long, long long> > > reverse_adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    adj[a - 1].emplace_back(b - 1, c);
    reverse_adj[b - 1].emplace_back(a - 1, c);
  }

  std::vector<long long> start_costs = dijkstras(adj, 0);
  std::vector<long long> reverse_costs = dijkstras(reverse_adj, n - 1);
  long long min_cost = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    for (const auto& a : adj[i]) {
      int n = a.first;
      int nc = a.second;
      if (start_costs[i] == LLONG_MAX || reverse_costs[n] == LLONG_MAX) continue;
      min_cost = std::min(min_cost, start_costs[i] + (nc / 2) + reverse_costs[n]);
    }
  }

  std::cout << min_cost << std::endl;

  return 0;
}