/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-04 10:34:02
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-08 09:55:45
 * @FilePath: \AlgorithmProblem\src\sub_array_anges.cpp
 * @Description: 2104. 子数组范围和
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    /**
     * @description:
     * @param {vector<int>} &nums
     * @return {long long}
     */
    long long subArrayRanges(vector<int> &nums)
    {
        int len = nums.size();
        stack<int> big_top_stack;
        stack<int> small_top_stack;
        vector<int> max_right;
        vector<int> min_right;
        long long max_sum = 0;
        long long min_sum = 0;
        max_right.resize(len);
        min_right.resize(len);
        fill(max_right.begin(), max_right.end(), len);
        fill(min_right.begin(), min_right.end(), len);
        for (int i = 0; i < len; i++)
        {
            while (!big_top_stack.empty() && nums[big_top_stack.top()] > nums[i])
            {
                min_right[big_top_stack.top()] = i;
                big_top_stack.pop();
            }
            big_top_stack.push(i);
            while (!small_top_stack.empty() && nums[small_top_stack.top()] < nums[i])
            {
                max_right[small_top_stack.top()] = i;
                small_top_stack.pop();
            }
            small_top_stack.push(i);
        }
        stack<int>().swap(big_top_stack);
        stack<int>().swap(small_top_stack);
        for (int i = len - 1; i >= 0; i--)
        {
            while (!big_top_stack.empty() && nums[big_top_stack.top()] >= nums[i])
            {
                int j = big_top_stack.top();
                min_sum += (j - i) * (min_right[j] - j) * (long long)nums[j];
                big_top_stack.pop();
            }
            big_top_stack.push(i);
            while (!small_top_stack.empty() && nums[small_top_stack.top()] <= nums[i])
            {
                int j = small_top_stack.top();
                max_sum += (j - i) * (max_right[j] - j) * (long long)nums[j];
                small_top_stack.pop();
            }
            small_top_stack.push(i);
        }
        while (!big_top_stack.empty())
        {
            int j = big_top_stack.top();
            min_sum += (j + 1) * (min_right[j] - j) * (long long)nums[j];
            big_top_stack.pop();
        }
        while (!small_top_stack.empty())
        {
            int j = small_top_stack.top();
            max_sum += (j + 1) * (max_right[j] - j) * (long long)nums[j];
            small_top_stack.pop();
        }
        return max_sum - min_sum;
    }
};

int main()
{
    return 0;
}