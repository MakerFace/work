/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-06
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
  struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& p) const { return x == p.x and y == p.y; }
    bool operator!=(const Point& p) const { return not(*this == p); }
  };
  struct Pose {
    Point head, tail;
    int state;  // 0 is horizontal, 1 is vertical
    Pose(int x1, int y1, int x2, int y2)
        : head(x1, y1), tail(x2, y2), state(0) {}
    bool operator==(const Pose& p) const {
      return head == p.head and tail == p.tail and state == p.state;
    }

    bool operator!=(const Pose& p) const { return not(*this == p); }
  };

 public:
  int minimumMoves(vector<vector<int>>& grid) {
    int action = -1;
    int n = static_cast<int>(grid.size());
    Pose start(0, 0, 0, 1);
    Pose end(n - 1, n - 1, n - 1, n - 2);
    queue<Pose> pose_q;
    while (not pose_q.empty() and pose_q.front() != end) {
      auto temp = pose_q.front();
      pose_q.pop();
      if (temp.state) {              // vertical state
        if (temp.head.x + 1 < n and  // in the bound
            not grid[temp.head.x + 1]
                    [temp.head.y]) {  // and no block ceil, move down
          temp.head.x++;
          temp.tail.x++;
          pose_q.push(temp);
          temp.head.x--;
          temp.tail.x--;
        }
        if (temp.head.y + 1 < n and  // in the bound
                                     // left side have no block ceil
            not(grid[temp.head.x][temp.head.y + 1] and
                grid[temp.tail.x][temp.tail.y + 1])) {  // move right
          temp.head.y++;
          temp.tail.y++;
          pose_q.emplace(std::move(temp));
        }
      } else {                       // horizontal
        if (temp.head.y + 1 < n and  // in the bound
            not grid[temp.head.x]
                    [temp.head.y + 1]) {  // no block ceil, move right
          temp.head.y++;
          temp.tail.y++;
          pose_q.push(temp);
          temp.head.y--;
          temp.tail.y--;
        }
        if (temp.head.x + 1 < n and  // in the bound
                                     // down side have no block ceil
            not(grid[temp.head.x + 1][temp.head.y] and
                grid[temp.tail.x + 1][temp.tail.y])) {  // move down
          temp.head.x++;
          temp.tail.x++;
          pose_q.emplace(std::move(temp));
        }
      }
      ++action;
    }
    if (not pose_q.empty() and pose_q.front() == end) return action;
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid{{0, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 1, 0},
                           {0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 1, 0},
                           {0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0}};
  Solution sol;
  std::cout << sol.minimumMoves(grid) << std::endl;
  return 0;
}
