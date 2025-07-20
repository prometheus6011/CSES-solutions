#include <iostream>
#include <vector>

std::vector<long long> range_query(const std::vector<long long>& x)
{
  std::vector<long long> prefix_sum(x.size(), 0);
  prefix_sum[0] = x[0];
  for (int i = 1; i < x.size(); ++i) {
    prefix_sum[i] = x[i] + prefix_sum[i - 1];
  }

  return prefix_sum;
}

int main()
{
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> x(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> x[i];

  std::vector<long long> prefix_sum = range_query(x);

  for (int i = 0; i < q; ++i) {
    int a, b;
    std::cin >> a >> b;

    if (a == 1) {
      std::cout << prefix_sum[b - 1] << std::endl;
    } else {
      std::cout << prefix_sum[b - 1] - prefix_sum[a - 2] << std::endl;
    }
  }

  return 0;
}