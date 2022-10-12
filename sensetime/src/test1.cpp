/**
 * @file test1.cpp
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
   * 图像旋转
   * @param img int整型vector<vector<>> 输入图像
   * @return int整型vector<vector<>>
   */
  vector<vector<int>> rotate_img(vector<vector<int>>& img) {
    // write code here
    int n = static_cast<int>(img.size());
    remove_reference_t<decltype(img)> ans(n, vector<int>(n, 0));
    for (int i = 0, a_j = n - 1; i < n; i++, a_j--) {
      for (int j = 0, a_i = 0; j < n; j++, a_i++) {
        ans[a_i][a_j] = img[i][j];
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> img{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution sol;
  auto ans = sol.rotate_img(img);
  for (auto& row : ans) {
    for (auto& col : row) {
      std::cout << col << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
