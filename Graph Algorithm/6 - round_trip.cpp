#include <algorithm>
#include <iostream>
#include <vector>

bool dfs(const std::vector<std::vector<int> >& adj, std::vector<int>& parent, std::vector<bool>& visited, int start, int par)
{
  visited[start] = true;
  for (const auto& e : adj[start]) {
    if (e == par) continue;
    if (visited[e]) {
      std::vector<int> cycle;
      cycle.push_back(e);
      for (int i = start; i != e; i = parent[i]) {
        cycle.push_back(i);
      }
      cycle.push_back(e);
      std::reverse(cycle.begin(), cycle.end());
      std::cout << cycle.size() << std::endl;
      for (int i : cycle) {
        std::cout << i + 1 << " ";
      }
      std::cout << std::endl;
      exit(0);
    }
    parent[e] = start;
    if (dfs(adj, parent, visited, e, start)) return true;
  }
  return false;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> parent(n, -1);
  std::vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i] && dfs(adj, parent, visited, i, -1)) {
      return 0;
    }
  }

  std::cout << "IMPOSSIBLE" << std::endl;

  return 0;
}