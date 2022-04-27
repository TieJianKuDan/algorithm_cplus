/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-27 09:36:00
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-27 10:48:51
 * @FilePath: \AlgorithmProblem\src\pacific_atlantic.cpp
 * @Description: 417. 太平洋大西洋水流问题(错误)
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <vector>
#include <unordered_set>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    struct pair_hash
    {
        template <class T1, class T2>
        size_t operator()(pair<T1, T2> const &pair) const
        {
            size_t h1 = hash<T1>()(pair.first);  //用默认的 hash 处理 pair 中的第一个数据 X1
            size_t h2 = hash<T2>()(pair.second); //用默认的 hash 处理 pair 中的第二个数据 X2
            return h1 ^ h2;
        }
    };
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        unordered_set<pair<int, int>, pair_hash> visited;
        vector<vector<int>> rets;
        queue<pair<int, int>> candidates;
        auto starts = GetAllStart(heights);
        for (int i = 0; i < starts.size(); i++)
        {
            auto start = starts[i];
            if (visited.find(start) == visited.end())
            {
                candidates.push(start);
                visited.insert(start);
                rets.push_back(vector<int>{start.first, start.second});
                bfs(visited, rets, candidates, heights);
            }
        }
        sort(rets.begin(), rets.end(), [](vector<int> v1, vector<int> v2)
             {
            if (v1[0] > v2[0]) {
                return true;
            } else if (v1[0] < v2[0]) {
                return false;
            } else {
                return v1[1] - v2[1] > 0 ? true : false;
            } });
        return rets;
    }
    void help(pair<int, int> &now, pair<int, int> &pre, unordered_set<pair<int, int>, pair_hash> &visited, vector<vector<int>> &rets, queue<pair<int, int>> &candidates, vector<vector<int>> &heights)
    {
        if (visited.find(now) == visited.end() && heights[pre.first][pre.second] <= heights[now.first][now.second])
        {
            rets.push_back(vector<int>{now.first, now.second});
            visited.insert(now);
            candidates.push(now);
        }
    }
    void bfs(unordered_set<pair<int, int>, pair_hash> &visited, vector<vector<int>> &rets, queue<pair<int, int>> &candidates, vector<vector<int>> &heights)
    {
        int row = (int)heights.size();
        int col = (int)heights[0].size();
        while (!candidates.empty())
        {
            auto p = candidates.front();
            candidates.pop();
            // up
            if (p.first - 1 >= 0)
            {
                pair<int, int> up(p.first - 1, p.second);
                help(up, p, visited, rets, candidates, heights);
            }
            // down
            if (p.first + 1 < row)
            {
                pair<int, int> down(p.first + 1, p.second);
                help(down, p, visited, rets, candidates, heights);
            }
            // right
            if (p.second + 1 < col)
            {
                pair<int, int> right(p.first, p.second + 1);
                help(right, p, visited, rets, candidates, heights);
            }
            // left
            if (p.second - 1 >= 0)
            {
                pair<int, int> left(p.first, p.second - 1);
                help(left, p, visited, rets, candidates, heights);
            }
        }
    }
    vector<pair<int, int>> GetAllStart(vector<vector<int>> &heights)
    {
        int row = (int)heights.size();
        int col = (int)heights[0].size();
        vector<pair<int, int>> rets;
        int max = 0;
        rets.push_back(pair<int, int>(0, col - 1));
        rets.push_back(pair<int, int>(row - 1, 0));
        for (int i = 1; i < row - 1; i++)
        {
            pair<int, int> p;
            for (int j = 0; j < col; j++)
            {
                if (heights[i][j] > max)
                {
                    max = heights[i][j];
                    p = pair<int, int>(i, j);
                }
            }
            rets.push_back(p);
            max = 0;
        }
        return rets;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input
    {
        {1548, 1421, 1767, 1678, 1323, 1073, 1147, 1240, 1857, 1913, 1967, 1763, 1864, 2010, 1558, 1256, 1916, 1818, 1605, 1398, 1102, 1176, 1503, 1064, 1279, 1428, 1213, 1652, 1720, 1520, 1434, 1258, 1282, 1191, 1277, 1947, 1605, 1765, 1176, 1451, 1667, 1484, 1556, 1521, 1835, 1103, 1118, 1740, 1262, 1065, 1479, 1353, 1230, 1971, 1406, 1498, 1740, 1961, 1139, 1802, 1822, 1915, 1401, 1446, 1095, 1667, 1382, 1689, 1422, 1899, 1482, 1430, 1372, 1027, 1292, 1196, 1471, 1400, 1277, 1722, 1454, 1745, 1064, 1025, 1057, 1811, 1512, 1786, 1761, 1992, 1929, 1573, 1896, 1319, 1360, 1980, 1328, 1731, 1011, 1739}, {1971, 481, 509, 331, 849, 791, 868, 309, 532, 134, 20, 327, 868, 73, 341, 914, 873, 194, 41, 976, 175, 960, 890, 413, 268, 239, 734, 585, 959, 734, 665, 271, 557, 517, 592, 396, 298, 802, 695, 172, 926, 705, 841, 136, 120, 524, 40, 984, 708, 71, 302, 225, 21, 182, 628, 632, 411, 705, 559, 712, 429, 215, 973, 977, 74, 907, 363, 714, 699, 401, 876, 615, 448, 59, 741, 559, 573, 123, 885, 623, 536, 177, 838, 900, 349, 809, 522, 102, 856, 423, 804, 275, 980, 119, 594, 44, 16, 948, 748, 705}, { 1692, 966, 662, 129, 15, 745, 678, 578, 210, 905, 543, 736, 424, 724, 978, 763, 875, 490, 207, 721, 256, 1001, 986, 226, 110, 571, 261, 468, 861, 351, 515, 894, 308, 519, 13, 313, 254, 34, 234, 806, 929, 767, 885, 344, 833, 853, 449, 698, 686, 647, 409, 932, 990, 738, 500, 443, 651, 751, 901, 502, 445, 407, 386, 743, 916, 741, 398, 513, 765, 622, 309, 37, 732, 536, 723, 555, 380, 162, 244, 56, 151, 995, 330, 132, 723, 820, 565, 364, 914, 808, 856, 349, 205, 584, 82, 464, 316, 470, 967, 423 }
    };
    s.pacificAtlantic(input);
}