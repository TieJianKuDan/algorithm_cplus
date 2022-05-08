/*
 * @Author: TieJianKuDan
 * @Date: 2022-05-08 09:05:28
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-05-08 09:17:54
 * @FilePath: \AlgorithmProblem\src\find_duplicates.cpp
 * @Description: 442. 数组中重复的数据
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved. 
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> rets;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                rets.push_back(nums[i]);
            }
            else
            {
                nums[abs(nums[i]) - 1] = -nums[nums[i] - 1];
            }
        }
        return rets;
    }
};

int main()
{
    Solution s;
    vector<int> input{4, 3, 2, 7, 8, 2, 3, 1};
    s.findDuplicates(input);
}