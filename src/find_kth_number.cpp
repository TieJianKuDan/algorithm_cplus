/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-23 09:09:20
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-23 10:26:00
 * @FilePath: \AlgorithmProblem\src\find_kth_number.cpp
 * @Description: 440. 字典序的第K小数字(根本不需要建树)
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        if (k > n)
        {
            return 0;
        }
        for (int i = 1; i <= n; i++)
        {
            root.add(i, &root);
        }
        return root.tranverse(&root, k, 0);
    }

    class Node
    {
    public:
        bool isEnd = false;
        Node *children[10];
        Node()
        {
            for (int i = 0; i < 10; i++)
            {
                children[i] = nullptr;
            }
        }
        void add(int num, Node *root)
        {
            stack<int> s;
            while (num > 0)
            {
                int temp = num % 10;
                num /= 10;
                s.push(temp);
            }
            while (!s.empty())
            {
                int temp = s.top();
                s.pop();
                if (root->children[temp] == nullptr)
                {
                    Node *child = new Node();
                    root->children[temp] = child;
                }
                root = root->children[temp];
            }
            root->isEnd = true;
        }
        int tranverse(Node *root, int &k, int ret)
        {
            int ret_ = 0;
            if (root == nullptr)
            {
                return 0;
            }
            if (root->isEnd)
            {
                k--;
                if (k == 0)
                {
                    return ret;
                }
            }
            for (int i = 0; i < 10; i++)
            {
                if (root->children[i] != nullptr)
                {
                    ret_ = tranverse(root->children[i], k, ret * 10 + i);
                    if (ret_)
                    {
                        break;
                    }
                }
            }
            return ret_;
        }
    };

private:
    Node root;
};

int main()
{
    Solution s;
    cout << s.findKthNumber(13, 2) << endl;
}