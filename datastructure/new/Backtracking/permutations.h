#pragma once

#include "../util.h"



/* ȫ���� I */
vector<vector<int>> permutationsI(vector<int> nums);

/* �����㷨��ȫ���� I  û���ظ�Ԫ��*/
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);

/* �����㷨��ȫ���� I  �����ظ�Ԫ��  1, 1, 3 */
void backtrack_repeat(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res);


void testPermutations();