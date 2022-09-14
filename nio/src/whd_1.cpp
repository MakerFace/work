/**
 * @file whd_1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-02
 */
#include <bits/stdc++.h>

using namespace std;

inline int last(int n) { return n & (~n + 1); }

int main(int argc, char const *argv[]) {
  int t, m;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long ans = 0;
    cin >> m;
    auto start = chrono::system_clock::now();
    for (int j = 1; j <= m; ++j) ans += j;
    auto end = chrono::system_clock::now();
    std::cout << (end - start).count() << std::endl;
    cout << ans << endl;
  }
  return 0;
}
