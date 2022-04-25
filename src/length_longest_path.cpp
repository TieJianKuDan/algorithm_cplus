/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-20 09:02:56
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-20 11:12:00
 * @FilePath: \AlgorithmProblem\src\length_longest_path.cpp
 * @Description:
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthLongestPath(string input)
    {
        return help(input, "\n\t", 0);
    }
    int help(const string &input, const string &split, int pre_len)
    {
        string split_ = split;
        split_.append("\t");
        int max_len = 0;
        vector<string> substrs(SplitStr(input, split));
        if (substrs.size() == 1) {
            if (substrs[0].find(".") != -1) {
                return pre_len + substrs[0].size();
            } else {
                return 0;
            }
        }
        for (int i = 1; i < substrs.size(); i++) {
            max_len = max(max_len, help(substrs[i], split_, pre_len + substrs[0].size() + 1)); 
        }
        return max_len;
    }
    vector<string> SplitStr(const string &input, const string &split)
    {
        int start = 0, end = 0;
        vector<string> res;
        while (end < input.size())
        {
            int start_ = start;
            while (end < input.size())
            {
                end = input.find(split, start_);
                int pos = end + split.size();
                if (pos < input.size() && input[pos] != '\t')
                    break;
                else
                    start_ = end + split.size();
            }
            res.push_back(input.substr(start, end - start));
            start = end + split.size();
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.lengthLongestPath("a") << endl;
}