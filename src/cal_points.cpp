/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-26 09:53:29
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-26 10:11:26
 * @FilePath: \AlgorithmProblem\src\cal_points.cpp
 * @Description: 682. 棒球比赛
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int sum = 0;
        vector<int> scores;
        for (auto op = ops.begin(); op != ops.end(); op++)
        {
            if (*op == "+")
            {
                auto p = scores.end() - 1;
                scores.push_back(*p + *(p - 1));
            }
            else if (*op == "D")
            {
                auto p = scores.end() - 1;
                scores.push_back(2 * (*p));
            }
            else if (*op == "C")
            {
                scores.pop_back();
            }
            else
            {
                scores.push_back(stoi(*op));
            }
        }
        for (auto score : scores)
        {
            sum += score;
        }
        return sum;
    }
};

int main()
{
    vector<string> input{"5", "2", "C", "D", "+"};
    Solution s;
    cout << s.calPoints(input) << endl;
}