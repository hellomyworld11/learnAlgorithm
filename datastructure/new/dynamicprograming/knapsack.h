#pragma once

#include "../util.h"
//��������
/* 0-1 �������������� */
int knapsack_DFS(vector<int> &wgt, vector<int> &val, int i, int c);

// ���� ���仯����
int knapsack_DFSmem(vector<int> &wgt, vector<int> &val, vector<vector<int>>& mem, int i, int c);

// ��̬�滮
int knapsack_DP(vector<int> &wgt, vector<int> &val, int cap);

void testKnapsack();
