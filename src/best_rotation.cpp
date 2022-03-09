/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-09 13:58:45
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-09 14:36:36
 * @FilePath: \AlgorithmProblem\src\best_rotation.cpp
 * @Description: 798. 得分最高的最小轮调
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        int ret_k = 0;
        int max_score = INT32_MIN;
        vector<int> ret;
        vector<int> diff_k;
        int n = nums.size();
        diff_k.resize(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int interval = i - nums[i];
            if (interval >= 0)
            {
                if ((int)diff_k.size() - 1 < interval + 1)
                {
                    diff_k.resize(interval + 2);
                }
                diff_k[0] += 1;
                diff_k[interval + 1] -= 1;
            }
            interval = i + n - nums[i];
            if (interval >= i + 1)
            {
                if ((int)diff_k.size() - 1 < interval + 1)
                {
                    diff_k.resize(interval + 2);
                }
                diff_k[i + 1] += 1;
                diff_k[interval + 1] -= 1;
            }
        }

        ret.resize(diff_k.size());
        ret[0] = diff_k[0];
        ret_k = 0;
        max_score = ret[0];

        for (int i = 1; i < diff_k.size(); i++)
        {
            ret[i] = ret[i - 1] + diff_k[i];
            if (ret[i] > max_score)
            {
                ret_k = i;
                max_score = ret[i];
            }
        }

        return ret_k;
    }
};

int main()
{
    vector<int> input = {2, 3, 1, 4, 0};
    Solution solution;
    cout << solution.bestRotation(input) << endl;
}