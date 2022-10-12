/**
 * @file test3.cpp
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
   * 在给定药材数量的数组中求不违反规定可以采集到的最大数量
   * @param nums int整型vector 每个区域的药材数（首尾区域是相邻的)
   * @return int整型
   */
  int pick(vector<int>& nums) {
    // write code here
    auto len = static_cast<int>(nums.size());
    if (len <= 1) {
      return 0;
    }

    vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 1; i < len; i++) {
      dp[i + 1] = max(dp[i],                 // 不采i
                      nums[i] + dp[i - 1]);  // 采i
    }
    return dp[len];
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  int n;
  cin >> n;
  vector<int> nums{4, 3};
  nums.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  auto ans = sol.pick(nums);
  std::cout << ans << std::endl;
  return 0;
}
