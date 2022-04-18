/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-18 09:05:12
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-18 09:47:49
 * @FilePath: \AlgorithmProblem\src\lexicographical_numbers.cpp
 * @Description: 386. 字典序排数
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        int max_depth = 0;
        int temp = n;
        vector<int> max_width;
        vector<int> res;
        while (temp > 0)
        {
            max_depth++;
            temp /= 10;
        }
        dfs(0, 0, max_depth, res, n);
        return res;
    }

private:
    void dfs(int depth, int pre, int max_depth, vector<int> &res, int max_num)
    {
        if (depth > max_depth)
        {
            return;
        }
        if (depth != 0 && pre <= max_num)
        {
            res.push_back(pre);
        }
        for (int i = 0; i <= 9; i++)
        {
            if (depth == 0 && i == 0)
            {
                continue;
            }
            dfs(depth + 1, pre * 10 + i, max_depth, res, max_num);
        }
    }
};

int main()
{
    Solution s;
    s.lexicalOrder(12);
}