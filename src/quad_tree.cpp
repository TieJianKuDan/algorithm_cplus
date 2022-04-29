/*
 * @Author: TieJianKuDan
 * @Date: 2022-04-29 09:34:19
 * @LastEditors: TieJianKuDan
 * @LastEditTime: 2022-04-29 09:48:44
 * @FilePath: \AlgorithmProblem\src\quad_tree.cpp
 * @Description: 427. 建立四叉树
 * Copyright (c) 2022 by TieJianKuDan, All Rights Reserved.
 */
#include <vector>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        Node *root = new Node();
        return build(grid, 0, (int)grid.size() - 1, 0, (int)grid[0].size() - 1, root);
    }
    Node *build(vector<vector<int>> &grid, int rs, int re, int cs, int ce, Node *node)
    {
        bool isLeaf = true;
        for (int i = rs; i <= re; i++)
        {
            for (int j = cs; j <= ce; j++)
            {
                if (grid[i][j] != grid[rs][cs])
                {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) {
                break;
            }
        }
        if (isLeaf)
        {
            node->isLeaf = true;
            node->val = grid[rs][cs];
            node->topLeft = nullptr;
            node->topRight = nullptr;
            node->bottomLeft = nullptr;
            node->bottomRight = nullptr;
        }
        else
        {
            node->isLeaf = false;
            node->val = 0;
            node->topLeft = new Node();
            node->topRight = new Node();
            node->bottomLeft = new Node();
            node->bottomRight = new Node();
            int rm = (re + rs - 1) >> 1;
            int cm = (cs + ce - 1) >> 1;
            build(grid, rs, rm, cs, cm, node->topLeft);
            build(grid, rs, rm, cm + 1, ce, node->topRight);
            build(grid, rm + 1, re, cs, cm, node->bottomLeft);
            build(grid, rm + 1, re, cm + 1, ce, node->bottomRight);
        }
        return node;
    }
};

int main()
{
    vector<vector<int>> grid{{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    Solution s;
    Node* root = s.construct(grid);
    return 0;
}