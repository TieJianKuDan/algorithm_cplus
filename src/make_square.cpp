/*
 * @Author: TieJianKuDan
 * @Date: 2022-06-01 14:01:13
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-06-01 14:03:02
 * @FilePath: \AlgorithmProblem\src\make_square.cpp
 * @Description: 473. 火柴拼正方形
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved. 
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool makesquare(vector<int>& matchsticks) {
    int sum = 0;
    for_each(matchsticks.begin(), matchsticks.end(),
             [&sum](int a) { sum += a; });
    if (sum % 4 != 0) {
      return false;
    }
    int len = sum / 4;
    int n = matchsticks.size();
    int max_s = (1 << n) - 1;
    // dp[s] 表示已经放好的火柴的组成的临时边的长度
    vector<int> dp(max_s + 1, -1);
    dp[0] = 0;
    for (int s = 1; s <= max_s; s++) {
      for (int k = 0; k < n; k++) {
        if ((s & (1 << k)) != 0) {
          int s_ = s & (~(1 << k));
          if (dp[s_] >= 0 && matchsticks[k] + dp[s_] <= len) {
            dp[s] = (matchsticks[k] + dp[s_]) % len;
            // 不管何种排列顺序，只要状态s确定了，那么dp[s]就是一样的
            break;
          }
        }
      }
    }
    return dp[max_s] == 0;
  }
};

int main() {}