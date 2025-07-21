#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

std::vector<std::vector<long long> >& floyd_warshalls(std::vector<std::vector<long long> >& grid, int n)
{
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][k] != LLONG_MAX && grid[k][j] != LLONG_MAX) grid[i][j] = std::min(grid[i][j], grid[i][k] + grid[k][j]);
      }
    }
  }

  return grid;
}

int main()
{
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<long long> > matrix(n, std::vector<long long>(n, LLONG_MAX));
  for (int i = 0; i < n; ++i) {
    matrix[i][i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    matrix[a - 1][b - 1] = std::min(matrix[a - 1][b - 1], 1LL * c);
    matrix[b - 1][a - 1] = std::min(matrix[a - 1][b - 1], 1LL * c);
  }

  std::vector<std::vector<long long> > distances = floyd_warshalls(matrix, n);

  for (int i = 0; i < q; ++i) {
    int a, b;
    std::cin >> a >> b;
    std::cout << (distances[a - 1][b - 1] == LLONG_MAX ? -1 : distances[a - 1][b - 1]) << std::endl;
  }

  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  */

  return 0;
}