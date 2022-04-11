/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-11 08:53:23
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-11 09:42:20
 * @FilePath: \AlgorithmProblem\src\numbers_with_unique_digits_.cpp
 * @Description: 357. 统计各位数字都不同的数字个数
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    unordered_set<int> visited;
    int count = 0;
    return dfs(visited, n - 1, count, false) + 1;
  }

 private:
  int dfs(unordered_set<int> visited, int index, int& count, bool started) {
    if (index < 0) {
      return ++count;
    }
    for (int i = 0; i <= 10; i++) {
      if (i == 10 && !started && index != 0) {
        dfs(visited, index - 1, count, false);
      } else if (i == 0 && !started) {
        continue;
      } else if (i != 10 && visited.find(i) == visited.end()) {
        visited.insert(i);
        dfs(visited, index - 1, count, true);
        visited.erase(i);
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.countNumbersWithUniqueDigits(2);
  return 0;
}