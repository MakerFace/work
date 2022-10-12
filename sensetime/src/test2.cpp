/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-22
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param nums int整型vector
   * @param k int整型
   * @return int整型vector
   */
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // write code here
    unordered_map<int, int> map;
    priority_queue<int, vector<int>, greater<int>> queue;
    for (auto &n : nums) {
      if (map.find(n) != map.end()) {
        map[n]++;
      } else {
        map[n] = 1;
        if (queue.size() < static_cast<uint32_t>(k)) queue.push(n);
      }
      if (queue.size() >= static_cast<uint32_t>(k) and
          map[n] > map[queue.top()]) {
        queue.pop();
        queue.push(n);
      }
    }
    vector<int> ans(k);
    int i = 0;
    while (not queue.empty()) {
      ans[i++] = queue.top();
      queue.pop();
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;
  auto ans = sol.topKFrequent(nums, k);
  for (auto &a : ans) {
    std::cout << a << ' ';
  }
  std::cout << std::endl;
  return 0;
}
