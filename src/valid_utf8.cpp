/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-13 10:07:35
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-13 10:53:54
 * @FilePath: \AlgorithmProblem\src\valid_utf8.cpp
 * @Description: 393. UTF-8 编码验证
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        auto point = data.begin();
        while (point != data.end())
        {
            if ((*point & 0x80) != 0)
            {
                if (IsDoubleOneZero(*point))
                {
                    point++;
                    if (point != data.end() && IsOneZero(*point))
                    {
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (IsTripleOneZero(*point))
                {
                    auto first = ++point;
                    if (first == data.end())
                    {
                        return false;
                    }
                    auto second = ++point;
                    if (second == data.end())
                    {
                        return false;
                    }
                    if (IsOneZero(*first) && IsOneZero(*second))
                    {
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (IsQuadraOneZero(*point))
                {
                    auto first = ++point;
                    if (first == data.end())
                    {
                        return false;
                    }
                    auto second = ++point;
                    if (second == data.end())
                    {
                        return false;
                    }
                    auto third = ++point;
                    if (third == data.end())
                    {
                        return false;
                    }
                    if (IsOneZero(*first) && IsOneZero(*second) && IsOneZero(*third))
                    {
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            point++;
        }
        return true;
    }

private:
    bool IsOneZero(int &target)
    {
        if ((target & 0x80) == 0)
        {
            return false;
        }
        else
        {
            return (target & 0x40) == 0;
        }
    }
    bool IsDoubleOneZero(int &target)
    {
        if ((target & 0xc0) == 0xc0)
        {
            return (target & 0x20) == 0;
        }
        else
        {
            return false;
        }
    }
    bool IsTripleOneZero(int &target)
    {
        if ((target & 0xe0) == 0xe0)
        {
            return (target & 0x10) == 0;
        }
        else
        {
            return false;
        }
    }
    bool IsQuadraOneZero(int &target)
    {
        if ((target & 0xf0) == 0xf0)
        {
            return (target & 0x8) == 0;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<int> input{197, 130, 1};
    Solution s;
    cout << s.validUtf8(input) << endl;
}