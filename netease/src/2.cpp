/**
 * @file 2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-04
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k, t;
  cin >> n >> k >> t;
  if (k <= t) {
    cout << -1 << endl;
    return 0;
  }
  string ans(t + 1, '1');
  int ones = k - t - 1;
  int zeros = n - k;
  while (ones and zeros) {
    ans += "01";
    --ones;
    --zeros;
  }
  if (ones) {
    cout << -1 << endl;
    return 0;
  }
  ans += string(zeros, '0');
  cout << ans << endl;
  return 0;
}