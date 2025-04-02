#pragma once

#include "../util.h"



/* 全排列 I */
vector<vector<int>> permutationsI(vector<int> nums);

/* 回溯算法：全排列 I  没有重复元素*/
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);

/* 回溯算法：全排列 I  不算重复元素  1, 1, 3 */
void backtrack_repeat(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);


void testPermutations();