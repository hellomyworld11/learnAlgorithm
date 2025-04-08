#pragma once
#include "../util.h"

/*给定一个共有 阶的楼梯，你每步可以上阶或者阶，请问有多少种方案可以爬到楼顶？*/



//1.回溯法穷举
void backtrack(vector<int>& choices, int state, int n, vector<int>& res);

int climbingStairs_Backtrack(int n);




void testClimbingStairs();

