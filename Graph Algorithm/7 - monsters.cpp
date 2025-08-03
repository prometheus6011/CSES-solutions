#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <string>

void backtrack(const std::vector<std::vector<char> >& par, const std::pair<int, int>& start, int nx, int ny)
{
  std::unordered_map<char, std::pair<int, int> > rev_mp = {
    { 'L', {0, 1} },
    { 'R', {0, -1} },
    { 'D', {-1, 0} },
    { 'U', {1, 0} }
  };
  std::string str;
  while (nx != start.first || ny != start.second) {
    str += par[nx][ny];
    int new_nx = nx + rev_mp[par[nx][ny]].first;
    int new_ny = ny + rev_mp[par[nx][ny]].second;
    nx = new_nx;
    ny = new_ny;
  }
  std::reverse(str.begin(), str.end());
  std::cout << str.size() << std::endl;
  std::cout << str << std::endl;
}

void person_bfs(const std::vector<std::vector<char> >& grid, std::deque<std::pair<int, int> >& dq, const std::vector<std::vector<int> >& time, int n, int m)
{
  std::vector<std::vector<bool> > visited(n, std::vector<bool>(m, false));
  const std::unordered_map<char, std::pair<int, int> > mp = {
    { 'R', {0, 1} },
    { 'L', {0, -1} },
    { 'U', {-1, 0} },
    { 'D', {1, 0} }
  };
  std::vector<std::vector<char> > parent(n, std::vector<char>(m, ' '));
  std::pair<int, int> start = dq.front();
  int curr_time = 1;

  while (!dq.empty()) {
    int sz = dq.size();

    for (int i = 0; i < sz; ++i) {
      int x = dq.front().first;
      int y = dq.front().second;
      dq.pop_front();

      if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        std::cout << "YES" << std::endl;
        backtrack(parent, start, x, y);
        exit(0);
      }

      for (const auto& [d, pr] : mp) {
        int nx = x + pr.first;
        int ny = y + pr.second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || grid[nx][ny] == '#' || curr_time >= time[nx][ny]) continue;
        visited[nx][ny] = true;
        parent[nx][ny] = d;
        dq.emplace_back(nx, ny);
      }
    }

    ++curr_time;
  }
}

void monsters_bfs(const std::vector<std::vector<char> >& grid, std::deque<std::pair<int, int> >& dq, std::vector<std::vector<int> >& time, int n, int m)
{
  std::vector<std::vector<bool> > visited(n, std::vector<bool>(m, false));
  const std::vector<std::pair<int, int> > dirs = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
  for (const auto& d : dq) {
    time[d.first][d.second] = 0;
  }
  int t = 1;
  while (!dq.empty()) {
    int sz = dq.size();

    for (int i = 0; i < sz; ++i) {
      int x = dq.front().first;
      int y = dq.front().second;
      dq.pop_front();

      for (const auto& d : dirs) {
        int nx = x + d.first;
        int ny = y + d.second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || grid[nx][ny] == '#') continue;
        time[nx][ny] = std::min(time[nx][ny], t);
        visited[nx][ny] = true;
        dq.emplace_back(nx, ny);
      }
    }

    ++t;
  }
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char> > grid(n, std::vector<char>(m));
  std::deque<std::pair<int, int> > monsters;
  std::deque<std::pair<int, int> > person;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> grid[i][j];
      if (grid[i][j] == 'M') monsters.emplace_back(i, j);
      if (grid[i][j] == 'A') person.emplace_back(i, j);
    }
  }

  std::vector<std::vector<int> > monster_time(n, std::vector<int>(m, INT_MAX));
  monsters_bfs(grid, monsters, monster_time, n, m);

  person_bfs(grid, person, monster_time, n, m);

  std::cout << "NO" << std::endl;

  return 0;
}