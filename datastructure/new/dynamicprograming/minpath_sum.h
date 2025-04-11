#pragma once
#include "../util.h"


/* ��С·���ͣ��������� �����ص�������  */
int minPathSumDFS(vector<vector<int>> &grid, int i, int j);

// ��С·���ͣ����仯���� 
int minPathSumDFSMem(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j);

/* ��С·���ͣ���̬�滮 */
int minPathSumDP(vector<vector<int>> &grid, int row, int col);

/* ��С·���ͣ���̬�滮 �ռ��Ż� */
int minPathSumDPComp(vector<vector<int>> &grid, int row, int col);

void testMinPath();