/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-24 09:22:27
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-24 09:33:24
 * @FilePath: \AlgorithmProblem\src\image_smoother.cpp
 * @Description: 661. 图片平滑器
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> ret;
        ret.resize(row);
        for (auto ele = ret.begin(); ele != ret.end(); ele++)
        {
            ele->resize(col);
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ret[i][j] = 0;
                int left = max(0, j - 1);
                int right = min(col - 1, j + 1);
                int top = max(0, i - 1);
                int bottom = min(row - 1, i + 1);
                int count = 0;
                for (int k = top; k <= bottom; k++)
                {
                    for (int l = left; l <= right; l++)
                    {
                        ret[i][j] += img[k][l];
                        count++;
                    }
                }
                ret[i][j] = ret[i][j] / count;
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution s;
    s.imageSmoother(img);
}