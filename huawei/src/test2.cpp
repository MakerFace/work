
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  std::array<Node *, 3> children;
  Node(int value = 0) : value(value) {}
};

int max_three(int a, int b, int c) {
  a = a > b ? a : b;
  a = a > c ? a : c;
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int maxValue = INT_MIN;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
int dfs(Node *root) {
  if (root == nullptr) return 0;
  auto left = max(dfs(root->children[0]), 0);
  auto middle = max(dfs(root->children[1]), 0);
  auto right = max(dfs(root->children[2]), 0);
  maxValue = max(maxValue, max_three(root->value + left + middle,
                                     root->value + left + right,
                                     root->value + middle + right));
  return root->value + max_three(left, middle, right);
}

int main() {
  // please define the C++ input here. For example: int a,b; cin>>a>>b;;
  // please finish the function body here.
  // please define the C++ output here. For example:cout<<____<<endl;
  // 19
  // 20 12 30 15 -1 -1 -1 -1 -1 -1 16 5 20 -1 -1 -1 15 -1 22
  int n;
  int m;
  cin >> n;
  queue<Node *> que;
  cin >> m;
  auto root = new Node(m);
  que.push(root);
  for (int i = 0; i < n; ++i) {
    auto top = que.front();
    que.pop();
    bool flag = false;
    for (int j = 0; j < 3; ++j) {
      if (not(cin >> m)) {
        flag = true;
        break;
      }
      if (m == -1) continue;
      top->children[j] = new Node(m);
      que.emplace(top->children[j]);
    }
    if (flag) break;
  }
  dfs(root);
  std::cout << maxValue << std::endl;
  return 0;
}
