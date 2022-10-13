/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-16
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
  long long key, value;
  Node(long long key = 0L, long long value = 0L) : key(key), value(value) {}
  friend bool operator<(Node& a, Node& b);
};

bool operator<(const Node& a, const Node& b) { return a.value > b.value; }

int main(int argc, char const* argv[]) {
  int n;
  long long m;
  long long k;
  cin >> n >> k;
  priority_queue<Node> queue;
  for (int i = 0; i < n; i++) {
    cin >> m;
    queue.emplace(static_cast<long long>(i + 1), m);
  }
  long long lazy = 0;
  while (not queue.empty() and k > 0) {
    long long sweet = (queue.top().value - lazy) * queue.size();
    if (sweet < k) {
      k -= sweet;
      lazy = queue.top().value;
      queue.pop();
    } else
      break;
  }
  n = queue.size();
  std::vector<Node> nodes;
  nodes.reserve(n);
  for (int i = 0; i < n; i++) {
    nodes.emplace_back(queue.top());
    queue.pop();
  }
  sort(nodes.begin(), nodes.end(),
       [](const Node& a, const Node& b) { return a.key < b.key; });

  std::cout << nodes[(k - 1) % n].key << std::endl;
  return 0;
}
