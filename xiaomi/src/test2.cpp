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
  stack<Node*> s;
  auto p = node;
  while (p or s.empty()) {
    if (p) {
      s.push(p);
      p = p->left;
    } else {
      p = s.top();
      cout << p->data << ' ';
      s.pop();
    }
  }
  return node;
}

int main(int argc, char** argv) {
  int n;
  Node* root = nullptr;
  std::queue<Node*> queue;
  bool left = true;
  while (cin >> n) {
    if (n == -1) break;
    if (root == nullptr) {
      root = new Node(n);
      queue.push(root);
    } else {
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