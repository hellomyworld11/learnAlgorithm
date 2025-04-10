#pragma once
#include "../util.h"

/*����һ������ �׵�¥�ݣ���ÿ�������Ͻ׻��߽ף������ж����ַ�����������¥����*/



//1.���ݷ����
void backtrack(vector<int>& steps, vector<int>& choices, int state, int n, vector<vector<int>>& res);
//���ݷ��õ�������¥�ݷ�������
int climbingStairs_Backtrack(int n, vector<vector<int>>& res);

//2. ����������������ص�������
int dfs(int i);

int climbinStairs_dfs(int n);

//3. ����������� ����¼�������ص������ⲻ���ظ�����  ���󶥲㣬�������ײ��¼�ײ��
int dfs(int i, vector<int> &memory);

int climbingStairs_dfsmemory(int n);

//4. ��̬�滮�� ���������� ��ͨ���ݹ�õ�����Ľ� 
int climbingStairs_dp(int n);

//5. ��̬�滮 �ռ��Ż�
int climbingStairs_dpComp(int n);

//6. ��̬�滮 ����¥����С����
int minCostClimbingStairsDp(vector<int>& cost);

// 7. ����һ������n�׵�¥�ݣ���ÿ��������1�׻���2�ף�
//����������������1�ף������ж����ַ�����������¥����
//�������޺�Ч�� ��Ҫ���Լ��
int climbingStairsConstraintDP(int n);


void testClimbingStairs();

