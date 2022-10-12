/**
 * @file sol2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-10
 */
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool solve(vector<int> &nums) {
    int count_g3 = 0, count_g5 = 0;
    vector<int> temp;
    int count = 0;
    for (auto &n : nums) {
      count += n;
      if (n % 5 == 0)
        count_g5 += n;
      else if (n % 3 == 0)
        count_g3 += n;
      else
        temp.emplace_back(n);
    }
    if (count % 2 != 0) return false;
    function<bool(size_t idx)> dfs;
    dfs = [&temp, &count_g3, &count_g5, &dfs](size_t idx) -> bool {
      if (idx == temp.size()) return count_g3 == count_g5;
      for (size_t i = idx; i < temp.size(); ++i) {
        count_g3 += temp[i];
        if (dfs(i + 1)) return true;
        count_g3 -= temp[i];
        count_g5 += temp[i];
        if (dfs(i + 1)) return true;
        count_g5 -= temp[i];
      }
      return false;
    };
    return dfs(0);
  }

 private:
  bool dfs(size_t idx, vector<int> &temp, int &count_g3, int &count_g5) {
    if (idx == temp.size()) return count_g3 == count_g5;
    for (size_t i = idx; i < temp.size(); ++i) {
      count_g3 += temp[i];
      if (dfs(i + 1, temp, count_g3, count_g5)) return true;
      count_g3 -= temp[i];
      count_g5 += temp[i];
      if (dfs(i + 1, temp, count_g3, count_g5)) return true;
      count_g5 -= temp[i];
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  char buf[1024];
  cin.get();
  cin.getline(buf, 1024);
  string line(buf);
  stringstream ss(line);
  int i = 0;
  while (ss >> nums[i++])
    ;
  Solution sol;
  std::cout << boolalpha << sol.solve(nums) << std::endl;
  return 0;
}
