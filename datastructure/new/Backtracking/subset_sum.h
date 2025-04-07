#pragma once
#include "../util.h"

/* �����㷨���Ӽ��� I  ���ظ��Ӽ�*/ 
void backtrack(vector<int> &state, int target, int total, vector<int> &choices, vector<vector<int>> &res);

vector<vector<int>> subsetSumINaive(vector<int> &nums, int target);

//�����㷨  û���ظ��Ӽ�
void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res);

//�����㷨  ���������������ظ�Ԫ��
void backtrack_repeatchoices(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res);

vector<vector<int>> subsetSumINaive_norepeat(vector<int> &nums, int target);


void testSubsetsum();