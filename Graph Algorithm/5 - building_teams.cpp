#include <iostream>
#include <vector>
#include <deque>

void bfs(const std::vector<std::vector<int> >& adj, std::vector<int>& visited, int start, std::vector<int>& res)
{
  res[start] = 1;
  visited[start] = true;
  std::deque<int> dq;
  dq.push_back(start);

  while (!dq.empty()) {
    int x = dq.front();
    dq.pop_front();
    for (const auto& neighbors : adj[x]) {
      if (res[neighbors] == res[x]) {
        std::cout << "IMPOSSIBLE" << std::endl;
        exit(0);
      }
      if (visited[neighbors]) continue;
      visited[neighbors] = true;
      res[neighbors] = 3 - res[x];
      dq.push_back(neighbors);
    }
  }
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

  std::vector<int> visited(n, false);
  std::vector<int> res(n, 0);


  for (int i = 0; i < n; ++i) {
    if (!visited[i]) bfs(adj, visited, i, res);
  }

  for (int i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}