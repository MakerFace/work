

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  /**
   *
   * @param arr int整型vector the array
   * @return int整型
   */
  int findNum(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int n_2 = n / 2;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        map[arr[i]]++;
        if (map[arr[i]] > n_2) {
            return map[arr[i]];
        }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
