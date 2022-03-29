/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-29 09:26:38
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-29 09:36:02
 * @FilePath: \AlgorithmProblem\src\max_consecutive_answers.cpp
 * @Description: 2024. 考试的最大困扰度
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(help(answerKey, 'T', k), help(answerKey, 'F', k));
    }

private:
    int help(string answerKey, char target, int k)
    {
        int l_sum = 0, r_sum = 0;
        int l_index = -1, r_index = -1;
        int ret = 0;
        int len = (int)answerKey.size();
        while (r_index < len - 1)
        {
            r_index++;
            if (answerKey[r_index] == target)
            {
                r_sum++;
            }
            while (l_index <= r_index && (r_sum - l_sum) > k)
            {
                l_index++;
                if (answerKey[l_index] == target)
                {
                    l_sum++;
                }
            }
            ret = max(ret, r_index - l_index);
        }
        return ret;
    }
};

int main()
{
    string input{"TTFF"};
    Solution s;
    cout << s.maxConsecutiveAnswers(input, 2) << endl;
}