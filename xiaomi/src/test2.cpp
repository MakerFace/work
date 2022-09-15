/**
 * @file test2.cpp
 * @brief 二叉搜索树转双链表
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-14
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data = 0, Node* left = nullptr, Node* right = nullptr)
      : data(data), left(left), right(right) {}
};

Node* convert(Node* node) {
  stack<tuple<int, Node*>> s;
  Node* ans = nullptr;
  Node* prev =
      nullptr;  // 前继指针，指向前一次输出的节点，它的右指向当前输出的节点，当前节点的左指向前继节点
  auto p = node;
  while (p or not s.empty()) {
    if (p) {
      s.push(make_tuple(0, p));  // first access
      p = p->left;
    } else {
      auto& tmp = s.top();
      p = get<1>(tmp);
      get<0>(tmp)++;
      if (get<0>(tmp) == 1) {  // second access
        if (ans == nullptr) {
          ans = p;
        }

        if (prev != nullptr) {
          prev->right = p;
        }
        p->left = prev;
        prev = p;
      } else if (get<0>(tmp) == 2) {  // third access
        p = nullptr;
        s.pop();
      }
      if (p) p = p->right;
    }
  }
  return ans;
}

int main(int argc, char** argv) {
  int n;
  Node* root = nullptr;
  std::queue<Node*> queue;
  bool left = true;
  while (cin >> n) {
    if (root == nullptr) {
      root = new Node(n);
      queue.push(root);
    } else {
      if (n == -1) {
        if (!left) {
          queue.pop();
          if (queue.empty()) break;
        }
        left = !left;
        continue;
      }
      if (left) {
        auto node = new Node(n);
        queue.front()->left = node;
        queue.push(node);
        left = !left;
      } else {
        auto node = new Node(n);
        queue.front()->right = node;
        queue.push(node);
        queue.pop();
        left = !left;
      }
    }
  }
  auto ans = convert(root);
  auto first = ans;
  while (first->right) {
    cout << first->data << " ";
    first = first->right;
  }
  cout << first->data << " ";
  while (first->left) {
    cout << first->data << " ";
    first = first->left;
  }
  cout << first->data << endl;
  return 0;
}