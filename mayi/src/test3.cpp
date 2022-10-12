/**
 * @file test3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-22
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    std::cout << -1 << std::endl;
    return 0;
  }
  deque<int> nums1(ceil(n * n / 2.0));
  deque<int> nums2(n * n / 2);
  vector<vector<int>> nums(n, vector<int>(n));

  bool flag = true;
  auto it1 = nums1.begin();
  auto it2 = nums2.begin();
  for (int i = 1; i <= n * n; i++) {
    if (flag) {
      *it1 = i;
      it1++;
      flag = !flag;
    } else {
      *it2 = i;
      it2++;
      flag = !flag;
    }
  }
  vector<int> select2{1, 2, 2, 2};
  vector<int> select1{1, 1, 2, 1};
  flag = true;
  for (int i = 0; i < n; i++) {  // 1,2,2,2,1,2,2,2
    // 1,1,2,1,1,1,2,1
    if (flag) {
      for (int j = 0; j < n; ++j) {
        if (select1[j % 4] == 1) {
          nums[i][j] = (nums1.at(0));
          nums1.pop_front();
        } else {
          nums[i][j] = (nums2.at(0));
          nums2.pop_front();
        }
      }
    } else {
      for (int j = 0; j < n; ++j) {
        if (select2[j % 4] == 1) {
          nums[i][j] = (nums1.at(0));
          nums1.pop_front();
        } else {
          nums[i][j] = (nums2.at(0));
          nums2.pop_front();
        }
      }
    }
    flag = !flag;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << nums[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
