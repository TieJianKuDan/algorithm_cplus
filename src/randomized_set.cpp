/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-13 09:08:34
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-13 10:57:09
 * @FilePath: \AlgorithmProblem\src\randomized_set.cpp
 * @Description: 380. O(1) 时间插入、删除和获取随机元素
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class RandomizedSet
{
private:
    int last;
    vector<int> k;
    unordered_map<int, int> m;

public:
    RandomizedSet() { this->last = 0; }

    bool insert(int val)
    {
        auto it = m.find(val);
        if (it == m.end())
        {
            m.insert({val, last});
            if (k.size() > last)
            {
                k[last] = val;
            }
            else
            {
                k.push_back(val);
            }
            last++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        auto it = m.find(val);
        if (it == m.end())
        {
            return false;
        }
        if (it->second < last - 1)
        {
            int temp = k[it->second];
            k[it->second] = k[last - 1];
            k[last - 1] = temp;
            m.find(k[it->second])->second = it->second;
        }
        if (m.erase(val) == 1)
        {
            last--;
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        srand(time(0));
        int index = rand() % last;
        return m.find(k[index])->first;
    }
};

int main()
{
    RandomizedSet r;
    cout << r.insert(0) << endl;
    cout << r.insert(1) << endl;
    cout << r.remove(0) << endl;
    cout << r.insert(2) << endl;
    cout << r.remove(1) << endl;
    cout << r.getRandom() << endl;
}