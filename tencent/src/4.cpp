/**
 * @file 4.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a ListNode类vector 指向每段碎片的开头
     * @return ListNode类
     */
    ListNode *solve(vector<ListNode *> &a)
    {
        // write code here
        int min_node = INT_MAX;
        ListNode *root = a[0];
        min_node = min(min_node, root->val);
        for (int i = 1; i < a.size(); ++i)
        {
            ListNode *p = a[i], *q = root;
            while (p != nullptr)
            {
                if (p->val == q->val)
                {
                    if (p->next == nullptr) // 交换root
                    {
                        p->next = q->next;
                        root = a[i];
                        if (q->next != nullptr && root->val == q->next->val)
                        {
                            p->next = nullptr;
                        }
                        q = root->next;
                        while (q->next != nullptr)
                        {
                            min_node = min(min_node, q->val);
                            if (q->next->val == root->val)
                            {
                                q->next = nullptr;
                                break;
                            }
                            q = q->next;
                        }
                        break;
                    }
                    else if (q->next == nullptr) // 拼接到root尾
                    {
                        q->next = p->next;
                        break;
                    }
                    q = q->next;
                }
                p = p->next;
            }
        }
        ListNode *q = root;
        bool found = false;
        while (q->next != nullptr)
        {
            if (q->next->val == min_node) // 比较当前值和间隔一个值
            {
                found = true;
                if (q->next->next != nullptr) // 在中间
                {
                    if (q->val > q->next->next->val) //顺时针
                    {
                        ListNode *end = q;
                        while (end->next != nullptr)
                        {
                            end = end->next;
                        }
                        end->next = root;
                        root = q->next;
                        q->next = nullptr;
                    }
                    else // 逆时针
                    {
                    }
                }
                else // 在尾部
                {
                    if (q->val > root->val) //顺时针
                    {
                    }
                    else //逆时针
                    {
                    }
                }
                break;
            }
            q = q->next;
        }
        if (!found) // 最小值在头上
        {
            if (q->val > root->next->val) //顺时针
            {
            }
            else // 逆时针
            {
            }
        }
        return root;
    }
};

ListNode *toList(vector<int> list)
{
    ListNode *root = new ListNode(list[0]);
    ListNode *p = root;
    for (int i = 1; i < list.size(); ++i)
    {
        p->next = new ListNode(list[i]);
        p = p->next;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<ListNode *> a;
    a.push_back(toList({10, 2, 3}));
    a.push_back(toList({7, 4, 5, 1, 10}));
    a.push_back(toList({3, 7, 4}));
    auto res = ans.solve(a);
    while (res)
    {
        std::cout << res->val << ",";
        res = res->next;
    }
    std::cout << "\b\n"
              << std::endl;
    return 0;
}
