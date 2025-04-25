#pragma once

#include "../util.h"
//背包问题
/* 0-1 背包：暴力搜索 */
int knapsack_DFS(vector<int> &wgt, vector<int> &val, int i, int c);

// 背包 记忆化搜索
int knapsack_DFSmem(vector<int> &wgt, vector<int> &val, vector<vector<int>>& mem, int i, int c);

// 动态规划
int knapsack_DP(vector<int> &wgt, vector<int> &val, int cap);

void testKnapsack();
