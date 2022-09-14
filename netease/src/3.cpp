/**
 * @file 3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-04
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {  // n
    cin >> nums[i];
    auto j = i;
    while (j > 0 and nums[j] > nums[j - 1]) {  // n
      swap(nums[j], nums[j - 1]);
      --j;
    }
  }

  if (n == 1) {
    cout << nums[0] - k * x << endl;
    return 0;
  }

  int m = 0;  // 分为m组，每个组最大最小值之差不超过x
  int start = 0;
  
  for (int i = 0; k and i < n; ++i) {
    if (nums[start] - nums[i] > x) {
      ++m;
    }
  }

  bool over = false;
  while (k and not over) {
    for (int i = 0; k and i < n; ++i) {
      if (nums[start] - nums[i] > x) {
        ++m;
      }
      int s = floor((nums[start] - nums[i]) / x);
      auto temp = s * (i - start);
      if (k < temp) {
        over = true;
        break;
      }
      k -= temp;
      int second = i;
      for (size_t j = 0; j < i; j++) {
        nums[j] -= s * x;
        while (second < n and nums[j] < nums[second]) {  // 减完之后resort
          swap(nums[j], nums[j]);
          ++second;
        }
      }
    }
  }
  while (k) {
    while (k and nums[0] > nums[1]) {
      nums[0] -= x;
      --k;
    }
    int j = 0;
    while (j < n and nums[j] < nums[j + 1]) {
      swap(nums[j], nums[j + 1]);
      ++j;
    }
  }
  cout << nums[0] << endl;
  return 0;
}
