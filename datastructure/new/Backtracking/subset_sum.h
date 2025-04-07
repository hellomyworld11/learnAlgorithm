#pragma once
#include "../util.h"

/* 回溯算法：子集和 I  有重复子集*/ 
void backtrack(vector<int> &state, int target, int total, vector<int> &choices, vector<vector<int>> &res);

vector<vector<int>> subsetSumINaive(vector<int> &nums, int target);

//回溯算法  没有重复子集
void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res);

//回溯算法  考虑输入数组有重复元素
void backtrack_repeatchoices(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res);

vector<vector<int>> subsetSumINaive_norepeat(vector<int> &nums, int target);


void testSubsetsum();