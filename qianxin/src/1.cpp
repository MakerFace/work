/**
 * @file 1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-08
 */
#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
using namespace std;

class Solution
{
    typedef struct Eating
    {
        TreeNode *node;
        bool eating;
        int flag;
        Eating() : node(nullptr), eating(false), flag(0) {}
        Eating(TreeNode *n, int f) : node(n), eating(false), flag(f) {}
    } Eating_t;

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 帮助夏娃挑选苹果
     * @param tree TreeNode类 苹果树
     * @return int整型
     */
    int eating(TreeNode *tree)
    {
        // write code here
        int result = 0;
        stack<Eating> s;
        queue<Eating> children;
        s.push(Eating(tree, 0));
        while (not s.empty())
        {
            Eating &t = s.top();
            if (t.flag != 1)
            {
                t.flag++;
                if (t.node->left)
                {
                    s.push(Eating(t.node->left, 0));
                }
                if (t.node->right)
                {
                    s.push(Eating(t.node->right, 0));
                }
            }
            else
            {
                s.pop();
                if (t.node->left or t.node->right) // 非叶子取决于子节点
                {
                    int child = 0;
                    auto left = children.front();
                    if (t.node->left)
                    {
                        children.pop();
                        if (left.eating)
                            child += t.node->left->val;
                    }

                    auto right = children.front();
                    if (t.node->right)
                    {
                        children.pop();
                        if (right.eating)
                            child += t.node->right->val;
                    }
                    t.eating = t.node->val > child;
                    if (t.eating)
                    {
                        result += t.node->val - child;
                    }
                }
                else
                {
                    t.eating = true;
                    result += t.node->val;
                }
                children.push(t);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto tree = list2tree({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::cout << ans.eating(tree) << std::endl;
    return 0;
}
