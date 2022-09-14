/**
 * @file 2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-13
 */

#include <bits/stdc++.h>

using namespace std;

inline bool judge(const string &str) {
  int ans1 = 0;
  int ans2 = 0;
  for (auto &ch : str) {
    if (ch == '1')
      ans1++;
    else
      ans2++;
  }
  return not (ans1 % 2 and ans2 % 2);
}

int main(int argc, char const *argv[]) {
  string str;
  int n;
  cin >> n;
  while (n--) {
    cin >> str;
    if (judge(str))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
