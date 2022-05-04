/*
 * @Author: TieJianKuDan
 * @Date: 2022-05-04 09:33:04
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-05-04 10:03:09
 * @FilePath: \AlgorithmProblem\src\find_the_winner.cpp
 * @Description: 1823. 找出游戏的获胜者
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved. 
 */
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        int start = 0;
        int last = n - 1;
        for (int i = 0; i < n; i++) {
            friends.push_back(i + 1);
        }
        for (int i = 1; i < n; i++) {
            int end = (start + k - 1) % (n - i + 1);
            for (int j = end; j < last; j++) {
                friends[j] = friends[j + 1];
            }
            last--;
            start = end % (n - i);
        }
        return friends[0];
    }
};

int main() {
    Solution s;
    s.findTheWinner(6, 5);
}