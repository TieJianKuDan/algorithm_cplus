/*
 * @Author: TieJianKuDan
 * @Date: 2022-05-22 09:43:42
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-05-22 11:11:14
 * @FilePath: \AlgorithmProblem\src\can_i_win.cpp
 * @Description: 464. 我能赢吗(能用二进制保存状态就用二进制，还有位操作优先级比逻辑操作低😅)
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int unused_num = 0;
    unordered_map<int, bool> mem;
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
      return false;
    }
    if (desiredTotal <= 0) {
      return true;
    }
    for (int i = 0; i < maxChoosableInteger; i++) {
      unused_num = unused_num | (1 << i);
    }
    bool ret = dfs(unused_num, desiredTotal, mem, maxChoosableInteger);
    return ret;
  }
  bool dfs(int unused_nums, int desiredTotal, unordered_map<int, bool> &mem,
           int max) {
    if (mem.count(unused_nums) == 1) {
      return mem.find(unused_nums)->second;
    }
    if (desiredTotal <= 0) {
      mem.insert({unused_nums, false});
      return false;
    }
    int mask = 1;
    for (int i = 1; i <= max; i++) {
      if ((unused_nums & mask) != 0) {
        bool ret = dfs(unused_nums & (~mask), desiredTotal - i, mem, max);
        if (!ret) {
          mem.insert({unused_nums, true});
          return true;
        }
      }
      mask = mask << 1;
    }
    mem.insert({unused_nums, false});
    return false;
  }
};

int main() {
  Solution s;
  cout << s.canIWin(20, 210) << endl;
}