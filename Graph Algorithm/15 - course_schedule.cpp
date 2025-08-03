#include <iostream>
#include <vector>
#include <stack>

bool dfs(const std::vector<std::vector<int> >& edges, int start, std::vector<bool>& visited, std::stack<int>& st, std::vector<bool>& in_stack)
{
  visited[start] = true;
  in_stack[start] = true;
  for (int i : edges[start]) {
    if (!visited[i]) {
      if (!dfs(edges, i, visited, st, in_stack)) return false; 
    } else if (in_stack[i]) {
      return false;
    }
  }
  in_stack[start] = false;
  st.push(start);
  return true;
}

std::vector<int> topological_sort(const std::vector<std::vector<int> >& edges, int n, bool& has_cycle)
{
  std::stack<int> st;
  std::vector<bool> visited(n, false);
  std::vector<bool> in_stack(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      if (!dfs(edges, i, visited, st, in_stack)) {
        has_cycle = true;
        return {};
      }
    }
  }
  std::vector<int> res;
  while (!st.empty()) {
    res.push_back(st.top());
    st.pop();
  }
  return res;
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
  }

  bool has_cycle = false;
  std::vector<int> res = topological_sort(adj, n, has_cycle);
  if (has_cycle) {
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
  }

  for (int i : res) {
    std::cout << i + 1 << " ";
  }
  std::cout << std::endl;

  return 0;
}