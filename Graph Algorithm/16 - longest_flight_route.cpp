#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

bool dfs(const std::vector<std::vector<int> >& adj, int start, int n, std::stack<int>& st, std::vector<bool>& visited, std::vector<bool>& in_stack)
{
  visited[start] = true;
  in_stack[start] = true;
  for (const auto& e : adj[start]) {
    if (!visited[e]) {
      if (!dfs(adj, e, n, st, visited, in_stack)) return false;
    } else if (in_stack[e]) {
      return false;
    }
  }
  in_stack[start] = false;
  st.push(start);
  return true;
}

std::vector<int> topological_sort(const std::vector<std::vector<int> >& adj, int n, std::stack<int>& st, std::vector<bool>& visited, std::vector<bool>& in_stack, bool& has_cycle)
{
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      if (!dfs(adj, i, n, st, visited, in_stack)) {
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

std::vector<int> longest_path(const std::vector<std::vector<int> >& adj, int n)
{
  std::stack<int> st;
  std::vector<bool> visited(n, false);
  std::vector<bool> in_stack(n, false);
  bool has_cycle = false;

  std::vector<int> res = topological_sort(adj, n, st, visited, in_stack, has_cycle);

  if (has_cycle) {
    return {};
  }

  std::vector<int> distance(n, INT_MIN);
  std::vector<int> predecessor(n, -1);
  distance[0] = 0;

  for (int a : res) {
    if (distance[a] != INT_MIN) {
      for (int b : adj[a]) {
        if (distance[b] < distance[a] + 1) {
          distance[b] = distance[a] + 1;
          predecessor[b] = a;
        }
      }
    }
  }

  if (distance[n - 1] == INT_MIN) return {};

  std::vector<int> path;
  for (int i = n - 1; i != -1; i = predecessor[i]) {
    path.push_back(i);
  }
  std::reverse(path.begin(), path.end());
  return path;
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

  std::vector<int> res = longest_path(adj, n);
  if (res.empty()) {
    std::cout << "IMPOSSIBLE" << std::endl;
  } else {
    std::cout << res.size() << std::endl;
    for (int i : res) {
      std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}