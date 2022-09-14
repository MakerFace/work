/**
 * @file 3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-13
 */

#include <bits/stdc++.h>

using namespace std;

enum Dir { UP = 1, LEFT = 2, DOWN = 4, RIGHT = 8 };

class Marix {
 public:
  Marix(int m, int n)
      : m(m),
        n(n),
        _matrix(m, string(n, '\0')),
        _flag(n, vector<bool>(n, 0)),
        step(0),
        ans(INT_MAX) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> _matrix[i][j];
      }
    }
  }

  int run(int i = 0, int j = 0) {
    if (i == m - 1 and j == n - 1) {
      ans = min(ans, step);
      return step;
    }
    _flag[i][j] = true;
    Dir dir = DOWN;
    if (i < m and can_go(i, j, dir)) {
      ++step;
      run(i + 1, j);
      --step;
    }
    dir = RIGHT;
    if (j < n and can_go(i, j, dir)) {
      ++step;
      run(i, j + 1);
      --step;
    }
    dir = UP;
    if (i > 0 and can_go(i, j, dir)) {
      ++step;
      run(i - 1, j);
      --step;
    }
    dir = LEFT;
    if (j > 0 and can_go(i, j, dir)) {
      ++step;
      run(i, j - 1);
      --step;
    }
    _flag[i][j] = false;
    return 0;
  }

  int getMin() const {
    if (ans > m + n) return -1;
    return ans;
  }

 private:
  bool can_go(int i, int j, Dir dir) {
    switch (dir) {
      {
        case Dir::UP:
          return (i > 1 and judge(_matrix[i][j], _matrix[i - 1][j]) and
                  not _flag[i - 1][j]);
        case Dir::LEFT:
          return (j > 1 and judge(_matrix[i][j], _matrix[i][j - 1]) and
                  not _flag[i][j - 1]);
        case Dir::DOWN:
          return (i < m - 1 and judge(_matrix[i][j], _matrix[i + 1][j]) and
                  not _flag[i + 1][j]);
        case Dir::RIGHT:
          return (j < n - 1 and judge(_matrix[i][j], _matrix[i][j + 1]) and
                  not _flag[i][j + 1]);
      }
    }
    return true;
  }

  inline bool judge(char cur, char next) {
    if (cur == 'r') {
      return next == 'r' or next == 'e';
    } else if (cur == 'e') {
      return next == 'e' or next == 'd';
    } else if (cur == 'd') {
      return next == 'd' or next == 'r';
    }
    return false;
  }

 private:
  int m, n;
  int step;
  int ans;
  vector<string> _matrix;
  vector<vector<bool>> _flag;
};

int main(int argc, char const *argv[]) {
  int m, n;
  cin >> m >> n;
  Marix matrix(m, n);
  matrix.run();
  cout << matrix.getMin() << endl;
  return 0;
}
