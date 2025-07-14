#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

void bfs(const std::vector<std::vector<int> >& adj, int n)
{
  std::vector<bool> visited(n, false);
  std::vector<int> parent(n, -1);
  std::deque<int> dq;

  dq.push_back(0);
  visited[0] = true;

  int res = 1;
  while (!dq.empty()) {
    int sz = dq.size();
    for (int i = 0; i < sz; ++i) {
      int x = dq.front();
      dq.pop_front();
      for (const auto& neighbors : adj[x]) {
        if (!visited[neighbors]) {
          parent[neighbors] = x;
          visited[neighbors] = true;
          dq.push_back(neighbors);
        }
        if (neighbors + 1 == n) {
          std::vector<int> ires;
          std::cout << res + 1 << std::endl;
          for (int i = neighbors; i != -1; i = parent[i]) {
            ires.push_back(i);
          }
          std::reverse(ires.begin(), ires.end());
          for (int i : ires) {
            std::cout << i + 1 << " ";
          }
          std::cout << std::endl;
          return;
        }
      }
    }
    ++res;
  }

  std::cout << "IMPOSSIBLE" << std::endl;
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  bfs(adj, n);

  return 0;
}