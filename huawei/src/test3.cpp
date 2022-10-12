#include <bits/stdc++.h>
using namespace std;
int help(const string& s, const int& k) {
  int n = s.size(), num = 0, curRes = 0, res = 0;
  char op = '+';
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
      // 输入在这统一转10进制
      if (isdigit(c))
        num = num * k + (c - '0');  // 0~9
      else
        num = num * k + (c - 'a') + 10;  // 10~16
    } else if (c == '(') {
      int j = i, cnt = 0;
      for (; i < n; ++i) {
        if (s[i] == '(') ++cnt;
        if (s[i] == ')') --cnt;
        if (cnt == 0) break;
      }
      num = help(s.substr(j + 1, i - j - 1), k);
    }
    if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
      switch (op) {
        case '+':
          curRes += num;
          break;
        case '-':
          curRes -= num;
          break;
        case '*':
          curRes *= num;
          break;
        case '/':
          curRes /= num;
          break;
      }
      if (c == '+' || c == '-' || i == n - 1) {
        res += curRes;
        curRes = 0;
      }
      op = c;
      num = 0;
    }
  }
  return res;
}

string solution(const string& s, const int& k) {
  auto res = help(s, k);
  if (res == 0) return "0";
  string ans;
  // 结果转k进制
  while (res) {
    int t = res % k;
    if (t < 10)
      ans.push_back(t + '0');
    else
      ans.push_back(t - 10 + 'a');
    res /= k;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(int argc, char const* argv[]) {
  string s;
  int k;
  cin >> s >> k;
  std::cout << solution(s, k) << std::endl;
  return 0;
}
