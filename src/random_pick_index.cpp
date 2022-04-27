/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-25 09:23:56
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-27 10:30:39
 * @FilePath: \AlgorithmProblem\src\random_pick_index.cpp
 * @Description: 398. 随机数索引
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved. 
 */
#include <unordered_map>
#include <vector>
#include <ctime>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> map;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(nums[i]);
            if (it != map.end()) {
                it->second.push_back(i);
            } else {    
                vector<int> v;
                v.push_back(i);
                map.insert({nums[i], v});
            }
        }
        
    }
    
    int pick(int target) {
        srand(time(0));
        auto it = map.find(target);
        if (it != map.end()) {
            int index = rand() % it->second.size();
            return it->second[index];
        } else {
            return -1;
        }
    }
};

int main() {}