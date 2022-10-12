
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  std::array<Node *, 3> children;
  Node(int value = 0) : value(value) {}
};

// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
int dfs(Node *root, int &left, int &middle, int &right) {
  if (root == nullptr) return 0;
left = dfs(root->children[0], );
  middle = dfs(root->children[1]);
  right = dfs(root->children[2]);
  return root->value + sum;
}

int main() {
  // please define the C++ input here. For example: int a,b; cin>>a>>b;;
  // please finish the function body here.
  // please define the C++ output here. For example:cout<<____<<endl;
  int n;
  cin >> n;
  //   cin.get();
  //   char buf[102400];
  //   cin.getline(buf, 102400);
  //   string str(buf);
  //   string temp;
  //   stringstream ss(str);
  queue<Node *> que;
  //   ss >> n;
  cin >> n;
  auto root = new Node(n);
  root->value = n;
  que.push(root);
  while (not que.empty()) {
    auto top = que.front();
    que.pop();
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
      if (not(cin >> n)) flag = false;
      if (n == -1) continue;
      top->children[i] = new Node(n);
      que.emplace(top->children[i]);
    }
    if (not flag) break;
  }
  int left = 0;
  int middle = 0;
  int right = 0;
  dfs(root, left, middle, right);

  return 0;
}
