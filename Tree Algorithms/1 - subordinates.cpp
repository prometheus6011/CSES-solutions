#include <iostream>
#include <vector>

int dfs(std::vector<std::vector<int> >& edges, int start, std::vector<int>& subtree_size)
{
  int cnt = 0;
  for (int e : edges[start]) {
    cnt += 1 + dfs(edges, e, subtree_size);
  }
  subtree_size[start] = cnt;
  return cnt;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > adj(n);
  for (int i = 1; i < n; ++i) {
    int a;
    std::cin >> a;
    --a;
    adj[a].push_back(i);
  }

  std::vector<int> subtree_size(n, 0);
  dfs(adj, 0, subtree_size);

  for (int i : subtree_size) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}