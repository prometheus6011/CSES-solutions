#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char> >& grid, int i, int j, int n, int m)
{
  if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#') return;

  grid[i][j] = '#';
  dfs(grid, i + 1, j, n, m);
  dfs(grid, i - 1, j, n, m);
  dfs(grid, i, j + 1, n, m);
  dfs(grid, i, j - 1, n, m);
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<char> > grid(n, std::vector<char>(m, ' '));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> grid[i][j];
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') {
        dfs(grid, i, j, n, m);
        ++res;
      }
    }
  }

  std::cout << res << std::endl;

  return 0;
}