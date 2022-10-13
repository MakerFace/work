/**
 * @file whd1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-27
 */

#include <bits/stdc++.h>

using namespace std;

const int RED = 'R' - 'A';
const int BLUE = 1;

struct Node {
  int color;
  int count;
  vector<int> others;
};

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<Node> nodes(n);
  string color;
  cin >> color;
  for (int i = 0; i < n; ++i) {
    nodes[i].color = (color[i] - 'A');
  }
  int p, q;
  for (int i = 0; i < n - 1; i++) {
    cin >> p >> q;
    nodes[p].others.push_back(q);
    nodes[q].others.push_back(p);
  }

  function<int(void)> dfs = [&]() -> int {

  };
  return 0;
}
