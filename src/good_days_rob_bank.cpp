/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-06 10:47:36
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-06 11:48:11
 * @FilePath: \AlgorithmProblem\src\good_days_rob_bank.cpp
 * @Description: 2100. 适合打劫银行的日子
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int start = time;
        int end = security.size() - time - 1;
        vector<int> res;
        if (start >= security.size() || end < 0)
        {
            return res;
        }
        vector<int> smaller;
        vector<int> bigger;
        smaller.resize(security.size());
        bigger.resize(security.size());
        for (int i = 0; i < security.size(); i++)
        {
            if (i == 0)
            {
                smaller[i] = security[i] < security[i + 1] ? 1 : 0;
                bigger[i] = security[i] > security[i + 1] ? 1 : 0;
                continue;
            }
            else if (i == security.size() - 1)
            {
                smaller[i] = smaller[i - 1];
                bigger[i] = bigger[i - 1];
                continue;
            }
            if (security[i] < security[i + 1])
            {
                smaller[i] = smaller[i - 1] + 1;
            }
            else
            {
                smaller[i] = smaller[i - 1];
            }
            if (security[i] > security[i + 1])
            {
                bigger[i] = bigger[i - 1] + 1;
            }
            else
            {
                bigger[i] = bigger[i - 1];
            }
        }
        for (int i = start; i <= end; i++)
        {
            bool flag = true;
            if (i > 0)
            {
                if (i - time - 1 >= 0)
                {
                    if ((smaller[i - 1] - smaller[i - time - 1]) > 0)
                    {
                        flag = false;
                    }
                }
                else
                {
                    if (smaller[i - 1] > 0)
                    {
                        flag = false;
                    }
                }
            }
            if (!flag)
            {
                continue;
            }
            if (i > 0)
            {
                if (bigger[i + time - 1] - bigger[i - 1] > 0)
                {
                    flag = false;
                }
            }
            else
            {
                if (time != 0 && bigger[i + time - 1] > 0)
                {
                    flag = false;
                }
            }
            if (flag)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};