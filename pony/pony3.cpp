/**
 * @file pony3.cpp
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  long long p = 0, o = 0, n = 0, res = 0;
  string str;
  cin >> str;

  for (auto &c : str) {
    if (c == 'p') ++p;
    if (p > 0 and c == 'o') {
      --p;
      ++o;
    }
    if (o > 0 and c == 'n') {
      --o;
      ++n;
    }
    if (n > 0 and c == 'y') {
      --n;
      ++res;
    }
  }
  std::cout << res << std::endl;
  return 0;
}
