#pragma once
#include "../util.h"


/* 最小路径和：暴力搜索 存在重叠子问题  */
int minPathSumDFS(vector<vector<int>> &grid, int i, int j);

// 最小路径和：记忆化搜索 
int minPathSumDFSMem(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j);

/* 最小路径和：动态规划 */
int minPathSumDP(vector<vector<int>> &grid, int row, int col);

/* 最小路径和：动态规划 空间优化 */
int minPathSumDPComp(vector<vector<int>> &grid, int row, int col);

void testMinPath();