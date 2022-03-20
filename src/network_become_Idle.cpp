/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-20 10:46:39
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-20 12:48:21
 * @FilePath: \AlgorithmProblem\src\network_become_Idle.cpp
 * @Description: 2039. 网络空闲的时刻
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        int ret = 0;
        vector<int> shortest_paths = CalcShortestPath(edges, patience.size());
        for (int i = 1; i < patience.size(); i++)
        {
            int route_len = shortest_paths[i] * 2;
            int count_message = (route_len - 1)  / patience[i];
            int time_sum = count_message * patience[i] + route_len + 1;
            ret = max(ret, time_sum);
        }
        return ret;
    }

private:
    /**
     * @description: 迪杰斯特拉算法求源点到所有点的最短路径(错误，应该建图后广度优先遍历)
     * @param {*}
     * @return {*}
     */
    vector<int> CalcShortestPath(vector<vector<int>> &edges, int len)
    {
        vector<int> rets(len);
        unordered_set<int> rest_points;
        for (int i = 0; i < rets.size(); i++)
        {
            if (i == 0)
                rets[i] = 0;
            else
                rets[i] = INT32_MAX;
        }
        for (int i = 1; i < len; i++)
        {
            rest_points.insert(i);
        }
        while (!rest_points.empty())
        {
            for (int i = 0; i < edges.size(); i++)
            {
                vector<int> edge = edges[i];
                if (rets[edge[0]] != INT32_MAX && rets[edge[1]] != INT32_MAX)
                    continue;
                if (rets[edge[0]] != INT32_MAX)
                {
                    rets[edge[1]] = min(rets[edge[0]] + 1, rets[edge[1]]);
                    rest_points.erase(edge[1]);
                }
                if (rets[edge[1]] != INT32_MAX)
                {
                    rets[edge[0]] = min(rets[edge[1]] + 1, rets[edge[0]]);
                    rest_points.erase(edge[0]);
                }
            }
        }
        return rets;
    }
};

int main()
{
    vector<vector<int>> edges{{5,7},{15,18},{12,6},{5,1},{11,17},{3,9},{6,11},{14,7},{19,13},{13,3},{4,12},{9,15},{2,10},{18,4},{5,14},{17,5},{16,2},{7,1},{0,16},{10,19},{1,8}};
    vector<int> patience{0,2,1,1,1,2,2,2,2,1,1,1,2,1,1,1,1,2,1,1};
    Solution s;
    cout << s.networkBecomesIdle(edges, patience) << endl;
}