/**
 * @file 最佳传送方案
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> mount(n);
  for (int i = 0; i < n; ++i) {
    cin >> mount[i];
  }

  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = mount[1] - mount[0] < 0 ? 0 : mount[1] - mount[0];
  for (int i = 2; i < n; i++) {
    // dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    int cost = INT_MAX;
    for (int j = 1; j <= k and i - j >= 0; ++j) {
      if (mount[i] <= mount[i - j]) {  // 无花费
        cost = min(cost, dp[i - j]);
      } else {  // 花费mount[i] - mount[i - j]
        cost = min(cost, dp[i - j] + mount[i] - mount[i - j]);
      }
    }
    dp[i] = cost;
  }

  std::cout << dp[n - 1] << std::endl;
  return 0;
}
