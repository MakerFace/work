/**
 * @file test3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */
#include <bits/stdc++.h>

using namespace std;

const int maxnums = 20000;
int** my_map;

bool isPoint(int i, int j) {
  if (not my_map[i][j]) return false;
  if (not my_map[i][j - 1] and not my_map[i - 1][j] and
      not my_map[i - 1][j - 1])
    return true;

  if (not my_map[i - 1][j] and not my_map[i][j + 1] and
      not my_map[i - 1][j + 1])
    return true;

  if (not my_map[i][j - 1] and not my_map[i + 1][j] and
      not my_map[i + 1][j - 1])
    return true;

  if (not my_map[i][j + 1] and not my_map[i + 1][j] and
      not my_map[i - 1][j - 1])
    return true;

  if (my_map[i][j - 1] and my_map[i - 1][j] and not my_map[i - 1][j - 1])
    return true;

  if (my_map[i - 1][j] and my_map[i][j + 1] and not my_map[i - 1][j + 1])
    return true;

  if (my_map[i][j - 1] and my_map[i + 1][j] and not my_map[i + 1][j - 1])
    return true;

  if (my_map[i][j + 1] and my_map[i + 1][j] and not my_map[i + 1][j + 1])
    return true;
  return false;
}

int main(int argc, char const* argv[]) {
  my_map = new int*[maxnums];
  for (int i = 0; i < maxnums; i++) {
    my_map[i] = new int[maxnums]{0};
  }

  int n;
  cin >> n;
  int x1, y1, x2, y2;
  while (n--) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; ++i) {
      for (int j = y1; j < y2; ++j) {
        my_map[i][j] = 1;
      }
    }
  }
  vector<vector<int>> points;
  for (int i = 0; i < maxnums; i++) {
    for (int j = 0; j < maxnums; j++) {
      /* code */
    }
  }

  return 0;
}
