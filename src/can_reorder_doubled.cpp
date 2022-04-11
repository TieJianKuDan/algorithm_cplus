/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-01 09:15:26
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-11 08:37:21
 * @FilePath: \AlgorithmProblem\src\can_reorder_doubled.cpp
 * @Description: 954. 二倍数对数组(超时)
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReorderDoubled(vector<int> &arr) {
    if ((int)arr.size() % 2 != 0) {
      return false;
    }
    unordered_map<int, int> records;
    unordered_map<int, int>::iterator it;
    for (auto ele : arr) {
      if ((it = records.find(ele)) != records.end()) {
        it->second++;
      } else {
        records.insert({ele, 1});
      }
    }
    return help(records);
  }

 private:
  bool help(unordered_map<int, int> records) {
    if (records.empty()) {
      return true;
    }
    auto it = records.begin();
    int key = it->first;
    it->second--;
    if (it->second == 0) {
      records.erase(it);
    }
    unordered_map<int, int>::iterator it_;
    if ((it_ = records.find(2 * key)) != records.end()) {
      it_->second--;
      if (it_->second == 0) {
        records.erase(it_);
      }
      if (help(records)) {
        return true;
      } else {
        if ((it_ = records.find(2 * key)) != records.end()) {
          it_->second++;
        } else {
          records.insert({2 * key, 1});
        }
      }
    }
    if (key % 2 == 0 && (it_ = records.find(key / 2)) != records.end()) {
      it_->second--;
      if (it_->second == 0) {
        records.erase(it_);
      }
      if (help(records)) {
        return true;
      }
    }
    return false;
  }
};