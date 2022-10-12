/**
 * @file compress.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-12
 */
#include <bits/stdc++.h>

// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

using namespace std;

std::string compress(const std::string& str) {
  if (str.empty()) return str;
  int n = static_cast<int>(str.length());
  int first = 0;
  int max_len = 0;
  int max_count = 0;
  std::string current;
  for (int len = 1; len <= n; len++) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = len + i; j < n; j += len) {
        auto s1 = str.substr(j - len, len);
        auto s2 = str.substr(j, len);
        if (s1 == s2) {
          ++count;
          if (count * len > max_count * max_len) {
            max_count = count;
            max_len = len;
            if (current != s1) {
              first = j - max_count * max_len;
              current = s1;
            }
            max_len = len;
          }
        } else {
          count = 0;
        }
      }
      count = 0;
    }
  }
  if (max_count == 0) return str;
  int last = first + (max_count + 1) * max_len;
  int last_len = str.size() - last;
  return compress(str.substr(0, first)) + to_string(max_count + 1) + "(" +
         compress(current) + ")" + compress(str.substr(last, last_len));
}

int main() {
  // please define the C++ input here. For example: int a,b; cin>>a>>b;;
  // please finish the function body here.
  // please define the C++ output here. For example:cout<<____<<endl;
  std::string str;
  bool work = true;
  cin >> str;
  str = compress(str);
  std::cout << str << std::endl;
  return 0;
}
