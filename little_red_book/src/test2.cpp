/**
 * @file 支配数
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  auto ans = 0;
  for (int i = 0; i < n - k; ++i) {
    unordered_map<int, int> map;
    bool flag = false;
    for (int j = i; j < n; j++) {
      map[nums[j]]++;
      if (map[nums[j]] >= k) {
        flag = true;
        break;
      }
    }
    // 左边乘右边
    if (flag) ans += (i + 1) * (n - k - i);
  }
  std::cout << ans << std::endl;
  return 0;
}
