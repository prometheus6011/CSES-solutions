#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

void dijkstras(const std::vector<std::vector<std::pair<int, int> > >& edges, int n, int k)
{
  std::vector<std::priority_queue<long long> > distance(n);
  distance[0].push(0);
  std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long> >, std::greater<std::pair<long long, long long> > > pq;
  pq.emplace(0, 0);  // (distance, node)

  while (!pq.empty()) {
    auto [dist, a] = pq.top();
    pq.pop();
    if (distance[a].size() > k || (distance[a].size() == k && dist > distance[a].top())) continue; 
    for (const auto& [b, w] : edges[a]) {
      long long new_cost = dist + w;
      if (distance[b].size() < k) {
        distance[b].push(new_cost);
        pq.emplace(new_cost, b);
      } else if (distance[b].top() > new_cost) {
        distance[b].pop();
        distance[b].push(new_cost);
        pq.emplace(new_cost, b);
      }
    }
  }

  std::vector<long long> res;
  while (!distance[n - 1].empty()) {
    res.push_back(distance[n - 1].top());
    distance[n - 1].pop();
  }
  std::sort(res.begin(), res.end());
  for (long long l : res) {
    std::cout << l << " ";
  }
  std::cout << std::endl;
}

int main()
{
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int> > > adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a, --b;
    adj[a].emplace_back(b, c);
  }

  dijkstras(adj, n, k);

  return 0;
}