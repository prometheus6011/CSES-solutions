#include <iostream>
#include <vector>
#include <deque>

std::vector<long long> generator(int x, int a, int b, int c, int n)
{
  std::vector<long long> res;
  res.push_back(x);
  for (int i = 1; i < n; ++i) {
    res.push_back((a * res[i - 1] + b) % c);
  }
  return res;
}

int main()
{
  int n, k;
  std::cin >> n >> k;
  int x, a, b, c;
  std::cin >> x >> a >> b >> c;
  std::vector<long long> vec = generator(x, a, b, c, n);

  long long res = 0;
  std::deque<int> dq;
  for (int i = 0; i < n; ++i) {
    while (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }
    while (!dq.empty() && vec[dq.back()] >= vec[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1) {
      res ^= vec[dq.front()];
    }
  }
  
  std::cout << res << std::endl;

  return 0;
}