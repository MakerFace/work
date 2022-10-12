/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> resources(n, vector<int>());
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    for (int j = 0; j < temp; j++) {
      int k;
      cin >> k;
      resources[i].push_back(k);
    }
  }

  unordered_set<int> loading_set;
  queue<int> loading;
  vector<int> use(m);  // all in used set
  int flag, load_res;
  int ans = 0;
  int use_count = 0;
  for (int i = 0; i < m; i++) {
    cin >> flag >> load_res;
    if (flag) {
      // todo ans++ when use:0->1
      loading.push(load_res);
      while (not loading.empty()) {
        auto res = loading_set.insert(loading.front());
        // not in loaded
        for (auto &ls : resources[loading.front()]) {
          res = loading_set.insert(ls);
          if (res.second) loading.push(ls);
        }
        loading.pop();
      }
      for (auto &ls : loading_set) {
        use_count += use[ls] == 0;
        use[ls]++;
      }
      ans = max(use_count, ans);
      loading_set.clear();
    } else {
      // todo ans-- when use:1->0
      loading.push(load_res);
      while (not loading.empty()) {
        auto res = loading_set.insert(loading.front());
        // not in loaded
        for (auto &ls : resources[loading.front()]) {
          res = loading_set.insert(ls);
          if (res.second) loading.push(ls);
        }
        loading.pop();
      }
      for (auto &ls : loading_set) {
        use[ls]--;
        use_count -= use[ls] == 0;
      }
      loading_set.clear();
    }
  }
  cout << ans << endl;
  return 0;
}
