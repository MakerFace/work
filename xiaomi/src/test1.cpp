/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-14
 */

#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

template <class Type>
class ListNode {
 public:
  Type data;
  ListNode<Type> *next;
};

class Solution {
 public:
  /* Write Code Here */
  ListNode<int> *reverseBetween(ListNode<int> *head, int left, int right) {
    if (left == right) return head;
    ListNode<int> *hair = new ListNode<int>();
    hair->next = head;
    auto pre = hair;
    auto next = hair->next;
    for (int i = 1; i < left; ++i) {
        pre = pre->next;
        next = next->next;
    }

    for (int i = left; i < right; ++i) {
        auto temp = next->next->next;
        next->next->next = pre->next;
        pre->next = next->next;
        next->next = temp;
    }
    head = hair->next;
    delete hair;
    return head;
  }
};
int main() {
  ListNode<int> *res = NULL;

  int head_size = 0;
  cin >> head_size;

  ListNode<int> *head = NULL, *head_curr = NULL;
  int head_item;
  for (int head_i = 0; head_i < head_size; head_i++) {
    cin >> head_item;

    ListNode<int> *head_temp = new ListNode<int>();
    head_temp->data = head_item;
    head_temp->next = NULL;
    if (head == NULL) {
      head = head_curr = head_temp;
    } else {
      head_curr->next = head_temp;
      head_curr = head_temp;
    }
  }

  int left;
  cin >> left;

  int right;
  cin >> right;

  Solution *s = new Solution();
  res = s->reverseBetween(head, left, right);
  while (res != NULL) {
    cout << res->data << " ";
    res = res->next;
  }
  cout << endl;

  return 0;
}
