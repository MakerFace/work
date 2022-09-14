/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> strings(n);
    vector<int> result;
    for (int i = 0; i < n; ++i)
    {
        cin >> strings[i];
    }
    int m = strings[0].size();
    for (int j = 0; j < m; ++j)
    {
        bool flag = false;
        int t = 0;
        for (int i = 0; i < n; ++i)
        {
            if (strings[i][j] != '0')
                flag = true;
            if (flag)
            {
                t *= 10;
                t += strings[i][j] - '0';
            }
        }
        result.push_back(t);
    }
    sort(result.begin(), result.end());
    std::cout << result[0];
    for (int i = 1; i < m; ++i)
    {
        std::cout << " " << result[i];
    }
    std::cout << std::endl;
    return 0;
}
