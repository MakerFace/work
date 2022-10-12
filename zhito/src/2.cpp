/**
 * @file 2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-06
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    vector<vector<int>> direct;
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<char>> used(m, vector<char>(n, 0));
    function<bool(int x, int y)> dfs;
    dfs = [&used, &grid, m, n, &direct, &dfs](int i, int j) -> bool {
      if (i == 0 or i == m - 1 or j == 0 or j == n - 1) return false;
      used[i][j] = 1;
      for (int i = 0; i < direct.size(); i++) {
        int new_i = i + direct[i][0];
        int new_j = j + direct[i][1];

        if (new_i >= 0 and new_i < m and new_j >= 0 and new_j < n and
            not used[new_i][new_j] and not grid[new_i][new_j]) {
          if (new_i == 0 or new_i == m - 1 or new_j == 0 or new_j == n - 1) {
            return false;

          } else if (not dfs(new_i, new_j)) {
            return false;
          }
        }
      }
      return true;
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0 and not used[i][j] and dfs(i, j)) ++count;
      }
    }
    return count;
  }
};

int main(int argc, char const *argv[])
{
  
  return 0;
}
