/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-13
 */

#include <bits/stdc++.h>

using namespace std;

inline bool yuanyin(char ch) {
  return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
}

bool judge(string::iterator begin) {
  int alphabet[26] = {0};
  static bool res[5] = {false, true, true, false, true};
  for (int i = 0; i < 5; ++i) {
    if (alphabet[*(begin + i) - 'a']) return false;
    alphabet[*(begin + i) - 'a'] = 1;
    if (yuanyin(*(begin + i)) != res[i]) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  int count = 0;
  for (auto it = str.begin(); it + 5 <= str.end(); it++) {
    if (not yuanyin(*it)) {
      count += judge(it);  // todo 返回第二个辅音的位置
    }
  }
  cout << count << endl;
  return 0;
}
