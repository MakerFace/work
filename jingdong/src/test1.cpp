/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  int x, y;
  while (t--) {
    cin >> x >> y;
    if (y - x <= 0) {
      std::cout << "-1 -1" << std::endl;
    } else {
      std::cout << 1 << " " << y - x << std::endl;
    }
  }
  return 0;
}
