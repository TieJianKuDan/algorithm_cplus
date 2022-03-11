/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-11 09:15:21
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-11 10:13:54
 * @FilePath: \AlgorithmProblem\src\count_highest_score_nodes.cpp
 * @Description: 2049. 统计最高分的节点数目 (超时)
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        int max = INT32_MIN;
        int count = 0;
        unordered_map<int, vector<int>> sons;

        for (int i = 0; i < parents.size(); i++)
        {
            auto iter = sons.find(parents[i]);
            if (iter != sons.end())
            {
                iter->second.push_back(i);
            }
            else
            {
                vector<int> son;
                son.push_back(i);
                sons.insert({parents[i], son});
            }
        }

        for (int i = 0; i < parents.size(); i++)
        {
            int temp = 1;
            vector<int> beside;
            if (parents[i] != -1)
            {
                beside.push_back(parents[i]);
            }
            if (sons.find(i) != sons.end())
            {
                for (int ele : sons.find(i)->second)
                {
                    beside.push_back(ele);
                }
            }
            for (int ele : beside)
            {
                temp *= (CalcTreeSize(parents, sons, ele, i));
            }
            if (temp > max)
            {
                count = 1;
                max = temp;
            }
            else if (temp == max)
            {
                count++;
            }
        }
        return count;
    }

private:
    int CalcTreeSize(vector<int> &parents, unordered_map<int, vector<int>> sons, int who, int father)
    {
        int size = 0;
        vector<int> nexts;
        if (parents[who] != father && parents[who] != -1)
        {
            nexts.push_back(parents[who]);
        }
        if (sons.find(who) != sons.end())
        {
            vector<int> temp = sons.find(who)->second;
            for (auto ele : temp)
            {
                if (ele != father)
                {
                    nexts.push_back(ele);
                }
            }
        }
        for (int ele : nexts)
        {
            size += CalcTreeSize(parents, sons, ele, who);
        }
        return size + 1;
    }
};

int main()
{
    vector<int> input{-1, 2, 0};
    Solution solution;
    cout << solution.countHighestScoreNodes(input) << endl;
}