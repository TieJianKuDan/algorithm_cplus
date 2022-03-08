/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-08 09:33:26
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-08 13:29:54
 * @FilePath: \AlgorithmProblem\src\plates_between_candles.cpp
 * @Description: 2055. 蜡烛之间的盘子
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        map<int, int> records;
        vector<int> index;
        vector<int> ret;
        int p = 0;
        while (p < s.length())
        {
            if (s[p] != '|')
            {
                p++;
            }
            else
            {
                break;
            }
        }
        if (p == s.length())
        {
            ret.resize(queries.size());
            fill(ret.begin(), ret.end(), 0);
            return ret;
        }
        int count = 0;
        while (p < s.length())
        {
            if (s[p] == '|')
            {
                records.emplace(p, count);
                index.push_back(p);
            }
            else
            {
                count++;
            }
            p++;
        }
        for (vector<int> interval : queries)
        {
            int left = interval[0], right = interval[1];
            if (left == right)
            {
                ret.push_back(0);
                continue;
            }
            int low = 0, high = index.size() - 1;
            while (low <= high)
            {
                int cen = (high - low) / 2 + low;
                if (index[cen] < left)
                {
                    low = cen + 1;
                }
                else
                {
                    high = cen - 1;
                }
            }
            left = index[low];
            low = 0;
            high = index.size() - 1;
            while (low <= high)
            {
                int cen = (high - low) / 2 + low;
                if (index[cen] > right)
                {
                    high = cen - 1;
                }
                else
                {
                    low = cen + 1;
                }
            }
            right = index[high];
            if (left > right)
            {
                ret.push_back(0);
            }
            else
            {
                ret.push_back(records[right] - records[left]);
            }
        }
        return ret;
    }
};

int main()
{
    Solution self;
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries{{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    auto ret = self.platesBetweenCandles(s, queries);
    copy(ret.begin(), ret.end(), ostream_iterator<int>(std::cout, ", "));
    return 0;
}