/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-04
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  vector<int> nums;    // k个一组
  vector<int> splits;  // 组分界
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }

  nums.resize(n);
  for (int i = 0; i < n; ++i) {  // n
    cin >> nums[i];
    auto j = i;
    while (j > 0 and nums[j] > nums[j - 1]) {  // n
      swap(nums[j], nums[j - 1]);
      --j;
    }
  }
  int start = 0;
  for (int i = 1; i < n; i++) {
    if (nums[i] - nums[start] / k == 1) {
      splits.push_back(start + 1);
      start = i;
    }
  }
  return 0;
}
