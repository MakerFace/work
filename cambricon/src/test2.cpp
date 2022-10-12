/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  int n;
  cin >> t;
  unordered_map<int, long long> map;
  map[0] = 1;
  function<long long(int)> func = [&](int n) -> long long {
    if (map.find(n) != map.end()) return map[n];
    if (n % 2)
      map[n] = 2 * func(n - 1);
    else
      map[n] = 1 + func(n - 1);
    return map[n];
  };
  while (t--) {
    cin >> n;
    if (map.find(n) == map.end()) {
      auto height = func(n);
      map[n] = height;
    }
    std::cout << map[n] << std::endl;
  }
  return 0;
}
