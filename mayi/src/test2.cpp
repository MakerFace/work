/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-22
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  string str, k;
  cin >> str >> k;
  long long ans = 0;
  // 1. 位数小于k
  long long len = str.size();
  for (long long i = 1; i < k.size(); ++i) {
    ans += len - i + 1;
  }
  // 2. 位数等于k，至少有一位小于k，不能大于
  // vector<int> next(k.size());
  // next[0] = 0;
  for (int i = 0; i <= len - static_cast<int>(k.size()); ++i) {
    bool equal = true;
    int j = 0;
    for (; j < k.size() and i + j < len; ++j) {
      if (k[j] > str[i + j]) {
        equal = false;
      } else if (k[j] < str[i + j]) {  // 有一个大于，失败
        j = 0;
        break;
      }
    }
    bool less = j == k.size();
    if (not equal and less) ans += 1;
  }

  std::cout << ans << std::endl;
  return 0;
}
