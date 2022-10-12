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
  int n;
  cin >> n;
  cin.get();                                              // get enter
  vector<vector<int>> mounts(n + 2, vector<int>(n + 2));  // padding
  char buf[100];
  for (int i = 0; i < n; ++i) {
    cin.getline(buf, 100);
    for (int j = 0; j < n; ++j) {
      mounts[i + 1][j + 1] = buf[j] - '0';
    }
  }
  function<bool(int i, int j)> func = [&](int i, int j) -> bool {
    return mounts[i - 1][j - 1] < mounts[i][j] and
           mounts[i - 1][j] < mounts[i][j] and
           mounts[i - 1][j + 1] < mounts[i][j] and
           mounts[i][j - 1] < mounts[i][j] and
           mounts[i][j + 1] < mounts[i][j] and
           mounts[i + 1][j - 1] < mounts[i][j] and
           mounts[i + 1][j] < mounts[i][j] and
           mounts[i + 1][j + 1] < mounts[i][j];
  };
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      count += func(i + 1, j + 1);
    }
  }
  std::cout << count << std::endl;
  return 0;
}
