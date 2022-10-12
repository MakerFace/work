/**
 * @file test3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  int n;
  const int MAX_LEN = 100000;
  char buf[MAX_LEN];
  vector<int> B(MAX_LEN);
  cin >> t;
  while (t--) {
    cin >> n;
    cin.get();
    cin.getline(buf, MAX_LEN);
    string str(buf);
    stringstream ss(str);
    int num;
    int i = 0;
    while (ss >> num) {
      B[i++] = num;
    }
    int count = 0;
    for (i = 1; i < n - 1; i++) {
      if (abs(1 - B[i - 1]) + abs(B[i + 1] - 1) >
          abs(B[i] - B[i - 1]) + abs(B[i + 1] - B[i]))
        B[i] = 1;
      count += abs(B[i] - B[i - 1]);
    }
    if (abs(1 - B[i - 1]) > abs(B[i] - B[i - 1])) B[i] = 1;
    count += abs(B[i] - B[i - 1]);
    std::cout << count << std::endl;
  }

  return 0;
}
