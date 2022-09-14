/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-07-17
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int *N = new int[n];
  int left = numeric_limits<int>::max(), right = numeric_limits<int>::max();
  int i = 0;
  for (; i < n; ++i) {
    cin >> N[i];
    if (N[i] == -1) break;
    left = min(left, N[i]);
  }
  for (; i < n; ++i) {
    cin >> N[i];
    right = min(right, N[i]);
  }
  cout << left + right << endl;
  delete N;
  return 0;
}
