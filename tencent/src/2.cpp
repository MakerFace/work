/**
 * @file 2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a int整型vector
     * @return int整型
     */
    int getNumber(vector<int> &a)
    {
        // write code here
        nums.push_back(2); // 1不是质数
        vector<int> temp;
        temp.reserve(a.size());
        while (a.size() != 1)
        {
            for (int i = 0; i < a.size(); ++i)
            {
                if (judge(i + 1))
                {
                    temp.push_back(a[i]);
                }
            }
            a.swap(temp);
            temp.clear();
        }
        return a[0];
    }

private:
    bool judge(int n)
    {
        if (n == 1)
            return false;
        for (auto var : nums)
        {
            if (var == n)
                return true;
            else if (n % var == 0)
                return false;
            else if (var >= n)
            {
                return true;
            }
        }
        nums.push_back(n);
        return true;
    }

private:
    vector<int> nums; // 质数表
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> a = {3, 1, 1, 4, 5, 6};
    std::cout << ans.getNumber(a) << std::endl;
    return 0;
}
