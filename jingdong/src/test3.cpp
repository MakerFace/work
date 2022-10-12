/**
 * @file test3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */
#include <bits/stdc++.h>

using namespace std;

long long C(int n, int m) {
  long long ans = 1;
  m = m > n / 2 ? n - m : m;
  for (int i = n; i < m; i++) {
    ans *= i--;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  if (n == 1)
    std::cout << 0 << std::endl;
  else {
    long long count = 0;
    int len = 26;
    long long temp = len;
    for (int i = 1; i < n; ++i) {
      if (i % 2)
        temp *= len - 1;
      else
        temp *= len;
      count += temp * C(n - 1, i);
    }
    std::cout << count << std::endl;
  }
  return 0;
}
