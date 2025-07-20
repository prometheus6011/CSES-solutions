#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

void dijkstras(const std::vector<std::vector<std::pair<long long, long long> > >& adj, int n)
{
  std::vector<bool> processed(n, false);
  std::vector<long long> distance(n, LLONG_MAX);
  distance[0] = 0;
  std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long> >, std::greater<std::pair<long long, long long> > > pq;
  pq.emplace(0, 0);  // (distance, node)
  while (!pq.empty()) {
    int a = pq.top().second;
    pq.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (const auto& u : adj[a]) {
      int b = u.first;
      int w = u.second;
      if (distance[a] + w < distance[b]) {
        distance[b] = distance[a] + w;
        pq.emplace(distance[b], b);
      }
    }
  }

  for (long long i : distance) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<long long, long long> > > adj(n);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    adj[a - 1].emplace_back(b - 1, c);
    // adj[b - 1].emplace_back(a - 1, c);
  }

  dijkstras(adj, n);

  return 0;
}