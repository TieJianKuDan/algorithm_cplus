/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-15 09:29:14
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-15 10:07:01
 * @FilePath: \AlgorithmProblem\src\count_max_or_subsets.cpp
 * @Description: 2044. 统计按位或能得到最大值的子集数目
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int max = INT32_MIN;
        int count = 0;
        dfs(nums, max, count, 0, 0);
        return count;
    }

private:
    int dfs(vector<int> &nums, int &max, int &count, int index, int ret)
    {
        if (index >= nums.size())
        {
            if (ret > max)
            {
                count = 1;
                max = ret;
            }
            else if (ret == max)
            {
                count++;
            }
            return max;
        }
        dfs(nums, max, count, index + 1, (ret | nums[index]));
        dfs(nums, max, count, index + 1, ret);
        return max;
    }
};

int main()
{
    return 0;
}