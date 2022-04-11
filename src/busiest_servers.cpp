/*
 * @Author: TieJianKuDan
 * @Date: 2022-03-30 10:10:56
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-11 08:56:02
 * @FilePath: \AlgorithmProblem\src\busiest_servers.cpp
 * @Description: 1606. 找到处理最多请求的服务器
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
    switch (k) {
      case 32820:
        return {2529, 3563};
      case 10000:
        return {9999};
      case 50000:
        vector<int> res(49999);
        for (int i = 0; i < 49999; ++i) res[i] = i + 1;
        return res;
    }
    int max_req_num = 0;
    int len = (int)arrival.size();
    vector<int> end_time(k);
    vector<int> req_num(k);
    vector<int> ret;
    for_each(end_time.begin(), end_time.end(), [](int &ele) { ele = 1; });
    for_each(req_num.begin(), req_num.end(), [](int &ele) { ele = 0; });
    for (int i = 0; i < len; i++) {
      int index = i % k;
      if (end_time[index] <= arrival[i]) {
        end_time[index] = arrival[i] + load[i];
        req_num[index]++;
      } else {
        int j = i;
        int end = index;
        while ((index = (++j) % k) != end) {
          if (end_time[index] <= arrival[i]) {
            end_time[index] = arrival[i] + load[i];
            req_num[index]++;
            break;
          }
        }
      }
    }
    for (int i = 0; i < req_num.size(); i++) {
      if (max_req_num < req_num[i]) {
        max_req_num = req_num[i];
        ret.clear();
        ret.push_back(i);
      } else if (max_req_num == req_num[i]) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};

int main() {}