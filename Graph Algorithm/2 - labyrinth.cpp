#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

void backtrack(const std::vector<std::vector<char> >& grid, int n, int m, const std::pair<int, int>& start, std::pair<int, int>& end)
{
  std::string res;
  std::unordered_map<char, std::pair<int, int> > reverse_mapping = { {'R', {0, -1}}, {'L', {0, 1}}, {'D', {-1, 0}}, {'U', {1, 0}} };
  while (end != start) {
    res += grid[end.first][end.second];
    std::pair<int, int> temp = end;
    end.first += reverse_mapping[grid[temp.first][temp.second]].first;
    end.second += reverse_mapping[grid[temp.first][temp.second]].second;
  }

  std::reverse(res.begin(), res.end());
  std::cout << res.size() << std::endl;
  std::cout << res << std::endl;
}

void bfs(std::vector<std::vector<char> >& grid, int n, int m, const std::pair<int, int>& start, std::pair<int, int>& end)
{
  std::vector<std::vector<bool> > visited(n, std::vector<bool>(m, false));
  visited[start.first][start.second] = true;
  std::deque<std::pair<int, int> > dq;
  dq.push_back(start);
  std::unordered_map<char, std::pair<int, int> > mp = { {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}} };

  while (!dq.empty()) {
    int x = dq.front().first;
    int y = dq.front().second;
    dq.pop_front();
    for (const auto& dirs : mp) {
      int nx = x + dirs.second.first;
      int ny = y + dirs.second.second;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny]) continue;
      if (grid[nx][ny] != '.' && std::make_pair(nx, ny) != end) continue;
      if (nx == end.first && ny == end.second) {
        grid[nx][ny] = dirs.first;
        std::cout << "YES" << std::endl;
        backtrack(grid, n, m, start, end);
        exit(0);
      }
      visited[nx][ny] = true;
      grid[nx][ny] = dirs.first;
      dq.emplace_back(nx, ny);
    }
  }

  std::cout << "NO" << std::endl;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char> > grid(n, std::vector<char>(m));
  std::pair<int, int> start;
  std::pair<int, int> end;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> grid[i][j];
      if (grid[i][j] == 'A') start = {i, j};
      if (grid[i][j] == 'B') end = {i, j};
    }
  }

  bfs(grid, n, m, start, end);

  return 0;
}