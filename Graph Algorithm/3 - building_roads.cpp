#include <iostream>
#include <iterator>
#include <vector>

void dfs(int node, std::vector<bool>& visited, const std::vector<std::vector<int> >& adj)
{
  visited[node] = true;
  for (int neighbor : adj[node]) {
    if (!visited[neighbor]) {
      dfs(neighbor, visited, adj);
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

  std::vector<bool> visited(n, false);
  std::vector<int> reps;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, visited, adj);
      reps.push_back(i + 1);
    }
  }

  std::cout << reps.size() - 1 << std::endl;
  for (int i = 1; i < reps.size(); ++i) {
    std::cout << reps[i - 1] << " " << reps[i] << std::endl;
  }

  return 0;
}