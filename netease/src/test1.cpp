/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

using namespace std;

double judge(string& str1, string& str2) {
  double ans = 0;
  if (str1[0] == str2[0]) ans += 2;
  if (str1.substr(1, str1.size() - 6) == str2.substr(1, str2.size() - 6))
    ans += 3;
  int i = str1.size() - 5, j = str2.size() - 5;
  if (str1.substr(i, 5) == str2.substr(j, 5))
    ans += 5;
  else {
    int max_len = 0;
    for (int first = i; first < str1.size(); ++first) {
      for (int second = j; second < str2.size(); ++second) {
        if (str1[first] == str2[second]) {
          int f = first, s = second;
          int len = 0;
          while (f < str1.size() and s < str2.size() and str1[f] == str2[s]) {
            len++;
            ++f;
            ++s;
          }
          max_len = max(max_len, len);
        }
      }
    }
    ans += max_len;
  }
  return ans / 10;
}

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  string str1, str2;
  double score = 0;
  for (int i = 0; i < n; ++i) {
    cin >> str1 >> str2;
    score += judge(str1, str2);
  }
//   score += ;
  printf("%.2f%\n", (score / n * 100) + 0.005);
  return 0;
}
