/**
 * @file 2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-08
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 得到短珠串的长度。【连三颗即成串，不必把所有珠子连起来】
     * @param pearls int整型vector<vector<>> n*2的二维数组，珠子的坐标，坐标值都为非负整数
     * @return int整型
     */
    int getMinLength(vector<vector<int>> &pearls)
    {
        // write code here
        int result = INT_MAX;
        sort(pearls.begin(), pearls.end(), [](vector<int> x, vector<int> y)
             { return (x[0] * x[0] + x[1] * x[1]) < (y[0] * y[0] + y[1] * y[1]); });
        for (size_t i = 0; i < pearls.size() - 2; ++i)
        {
            result = min(result, m_dis(pearls[i], pearls[i + 1], pearls[i + 2]));
        }
        return result;
    }

private:
    int m_dis(vector<int> x, vector<int> y, vector<int> z)
    {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]) + abs(y[0] - z[0]) + abs(y[1] - z[1]);
    }
};

int main(int argc, char const *argv[])
{
    Matrix<int> pearls = {{10, 10}, {10, 11}, {11, 12}};
    Solution ans;
    std::cout << ans.getMinLength(pearls) << std::endl;
    return 0;
}
