/**
 * @file 3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int T, n;
    cin >> T;
    vector<uint32_t> f(100000);
    f[1] = f[2] = 1;
    int size = 2;
    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        if (n >= size)
        {
            for (int j = size + 1; j <= n; ++j)
            {
                long long temp = f[j - 1] + f[j - 2];
                f[j] = temp % 1000000007;
            }
            size = n;
        }
        std::cout << f[n] << std::endl;
    }
    return 0;
}
