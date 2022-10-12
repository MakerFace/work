/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-22
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int opt;
  int i;
  int x;
  while (q) {
    cin >> opt;
    if (opt == 1) {
      cin >> i >> x;
      a[i - 1] = x;
    } else if (opt == 2) {
      cin >> i >> x;
      int count = 0;
      for (int j = 0; j < i; ++j) {
        count += a.at(j) == x;
      }
      std::cout << count << std::endl;
    }
    --q;
  }

  return 0;
}
