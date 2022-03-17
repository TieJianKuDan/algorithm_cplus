/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-17 09:04:43
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-03-17 09:44:33
 * @FilePath: \AlgorithmProblem\src\longest_word.cpp
 * @Description: 720. 词典中最长的单词
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(
            words.begin(), words.end(), [](auto ele1, auto ele2)
            {
                if (ele1.size() == ele2.size())
                {return ele1 > ele2;}
                else {return ele1.size() < ele2.size();} });
        unordered_set<string> records(words.size());
        for (auto p = words.begin(); p < words.end(); p++)
        {
            records.insert(*p);
        }
        for (auto p = words.end() - 1; p >= words.begin(); p--)
        {
            bool flag = true;
            string temp = (*p).substr(0, p->size() - 1);
            while (temp.size() > 0)
            {
                if (records.find(temp) == records.end())
                {
                    flag = false;
                    break;
                } else {
                    temp = temp.substr(0, temp.size() - 1);
                }
            }
            if (flag) {
                return *p;
            }
        }
        return "";
    }
};

int main()
{
    vector<string> input{
        "yo", "ew", "fc", "zrc", "yodn", "fcm", "qm", "qmo", "fcmz", "z", "ewq", "yod", "ewqz", "y"};
    Solution s;
    cout << s.longestWord(input) << endl;
}
