/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */

#include <bits/stdc++.h>

using namespace std;

int Kmin(vector<int>::iterator first, vector<int>::iterator last) {
  int k = (last - first + 1) / 2;
  priority_queue<int> pq;
  while (first != last) {
    pq.push(*first);
    ++first;
    if (pq.size() > k) {
      pq.pop();
    }
  }
  return pq.top();
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  //   for (int i = 0; i < n; ++i) {
  // cin >> nums[i];
  //   }
  generate_n(nums.begin(), n, []() {
    static int i = 1;
    return i++;
  });
  int count = 0;
  for (auto first = nums.begin(); first != nums.end(); ++first) {
    for (auto last = first; last != nums.end(); ++last) {
      count += Kmin(first, last + 1);
    }
  }
  std::cout << count << std::endl;
  return 0;
}
