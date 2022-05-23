/*
 * @Author: TieJianKuDan
 * @Date: 2022-05-23 09:16:46
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-05-23 11:03:38
 * @FilePath: \AlgorithmProblem\src\cut_off_tree.cpp
 * @Description: 675. 为高尔夫比赛砍树
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved. 
 */
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct Pair_Hash {
  size_t operator()(const pair<int, int> &p) const {
    return hash<int>{}(p.first) ^ hash<int>{}(p.second);
  }
};

struct VectorLess {
  bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
    return lhs[0] < rhs[0] ? false : true;
  }
};

ostream &operator<<(ostream &out, unordered_set<pair<int, int>, Pair_Hash> &A) {
  for (auto iter = A.begin(); iter != A.end(); iter++) {
    out << "(" << iter->first << "," << iter->second << ")";
  }
  return out;
}

ostream &operator<<(ostream &out, vector<int, allocator<int>> A) {
  out << "[";
  for (auto iter = A.begin(); iter != A.end();) {
    out << *iter;
    if (++iter != A.end()) {
      out << ",";
    }
  }
  out << "]";
  return out;
}

class Solution {
 public:
  unordered_set<pair<int, int>, Pair_Hash> visited;
  int cutOffTree(vector<vector<int>> &forest) {
    int step = 0;
    bool is_block = false;
    priority_queue<vector<int>, vector<vector<int>>, VectorLess> trees;
    for (int i = 0; i < forest.size(); i++) {
      for (int j = 0; j < forest[i].size(); j++) {
        if (forest[i][j] != 0 && forest[i][j] != 1) {
          trees.push(vector<int>{forest[i][j], i, j});
        }
      }
    }
    pair<int, int> start(0, 0);
    while (!trees.empty()) {
      vector<int> tree = trees.top();
      pair<int, int> end(tree[1], tree[2]);
      int part_step = calc_shortest_rout(start, end, forest);
      if (part_step == -1) {
        is_block = true;
        break;
      }
      step += part_step;
      trees.pop();
      start = end;
    }
    return is_block ? -1 : step;
  }
  int calc_shortest_rout(const pair<int, int> &start, const pair<int, int> end,
                         const vector<vector<int>> &forest) {
    queue<pair<int, int>> q;
    int step = 0;
    q.push(start);
    bool isEnd = false;
    while (!q.empty()) {
      int len = (int)q.size();
      for (int i = 0; i < len; i++) {
        pair<int, int> next = q.front();
        q.pop();
        if (next.first == end.first && next.second == end.second) {
          isEnd = true;
          break;
        }
        if (next.first - 1 >= 0 && forest[next.first - 1][next.second] != 0) {
          if (!visited.count(pair<int, int>(next.first - 1, next.second))) {
            pair<int, int> up(next.first - 1, next.second);
            q.push(up);
            visited.insert(up);
          }
        }
        if (next.first + 1 < forest.size() &&
            forest[next.first + 1][next.second] != 0) {
          if (!visited.count(pair<int, int>(next.first + 1, next.second))) {
            pair<int, int> down(next.first + 1, next.second);
            q.push(down);
            visited.insert(down);
          }
        }
        if (next.second - 1 >= 0 && forest[next.first][next.second - 1] != 0) {
          if (!visited.count(pair<int, int>(next.first, next.second - 1))) {
            pair<int, int> left(next.first, next.second - 1);
            q.push(left);
            visited.insert(left);
          }
        }
        if (next.second + 1 < forest[0].size() &&
            forest[next.first][next.second + 1] != 0) {
          if (!visited.count(pair<int, int>(next.first, next.second + 1))) {
            pair<int, int> right(next.first, next.second + 1);
            q.push(right);
            visited.insert(right);
          }
        }
      }
      if (isEnd) {
        break;
      }
      step++;
    }
    return isEnd ? step : -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> forest{{1, 2, 3}, {0, 0, 4}, {7, 6, 5}};
  cout << s.cutOffTree(forest) << endl;
}