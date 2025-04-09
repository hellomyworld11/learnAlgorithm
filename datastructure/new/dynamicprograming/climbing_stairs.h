#pragma once
#include "../util.h"

/*给定一个共有 阶的楼梯，你每步可以上阶或者阶，请问有多少种方案可以爬到楼顶？*/



//1.回溯法穷举
void backtrack(vector<int>& steps, vector<int>& choices, int state, int n, vector<vector<int>>& res);
//回溯法得到所有爬楼梯方案步骤
int climbingStairs_Backtrack(int n, vector<vector<int>>& res);

//2. 深度搜索法，会有重叠子问题
int dfs(int i);

int climbinStairs_dfs(int n);

//3. 深度搜索法， 带记录搜索，重叠子问题不用重复计算  先求顶层，依赖到底层记录底层解
int dfs(int i, vector<int> &memory);

int climbingStairs_dfsmemory(int n);

//4. 动态规划法 先求子问题 再通过递归得到顶层的解 
int climbingStairs_dp(int n);

//5. 动态规划 空间优化
int climbingStairs_dpComp(int n);

void testClimbingStairs();

