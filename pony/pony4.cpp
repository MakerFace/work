/**
 * @file 4.cpp
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  long long ans = 0;
  for (int i = 0; i <= n - m;) {
    int min_num = INT_MAX;
    int k = -1;
    for (int j = i; j < i + m; j++) {  // 窗口为m，检测最小值
      if (min_num >= nums[j]) {
        min_num = nums[j];
        k = j;
      }
    }
    for (int j = i; j < i + m; j++) {
      nums[j] -= min_num;
    }
    i = k + 1;  // 最小值的下一个
  }

  for (int i = 0; i < n; i++) {
    ans += nums[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
