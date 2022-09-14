/**
 * @file 2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-07-17
 */
#include <bits/stdc++.h>

using namespace std;

int binary_search(int *arr, int len, int val) {
  int left = 0, right = len;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] == val) {
      return val;
    }
    if (arr[mid] > val) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  if (arr[left] <= val)
    return arr[left];
  else
    return arr[left - 1];
}

int main(int argc, char const *argv[]) {
  int n;
  int *table = new int[1000];
  table[0] = 0;
  int len;
  for (len = 1; len < 1000; ++len) {
    table[len] += table[len - 1] + len * len;
    if (table[len] > 1e9) {
      --len;
      break;
    }
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int m, ans = 0;
    // n*(2n+1)*(n+1)/6
    cin >> m;
    ans = binary_search(table, len, m);
    cout << ans << endl;
  }

  return 0;
}
