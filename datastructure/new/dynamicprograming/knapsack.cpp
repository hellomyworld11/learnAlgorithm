#include "knapsack.h"

int knapsack_DFS(vector<int> &wgt, vector<int> &val, int i, int c)
{
	//������Ϊ0 ���� ��Ʒ�����꣬��ֱ�ӷ���
	if (i == 0 || c == 0)
	{
		return 0;
	}

	//��Ϊ�����±��0��ʼ�����Ե�i����Ʒ������Ϊwgt[i-1]

	//��ǰ��Ʒ������������������
	if (wgt[i-1] > c)
	{
		return knapsack_DFS(wgt, val, i - 1, c);
	}

	//���㲻���뱳�� �� ���뱳������ֵ
	int put_yes = knapsack_DFS(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
	int put_no = knapsack_DFS(wgt, val, i - 1, c);
	return max(put_yes, put_no);
}

int knapsack_DFSmem(vector<int> &wgt, vector<int> &val, vector<vector<int>>& mem, int i, int c)
{
	if (i == 0 || c == 0)
	{
		return 0;
	}
	if (mem[i][c] != -1)
	{
		return mem[i][c];
	}

	if (wgt[i-1] > c)
	{
		return knapsack_DFSmem(wgt, val, mem, i - 1, c);
	}

	int put_yes = knapsack_DFSmem(wgt, val, mem, i - 1, c - wgt[i - 1]) + val[i-1];
	int put_no = knapsack_DFSmem(wgt, val, mem, i - 1, c);
	mem[i][c] = max(put_no, put_yes);
	return mem[i][c];
}

int knapsack_DP(vector<int> &wgt, vector<int> &val, int cap)
{
	int n = wgt.size();
	vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));

	//��ʼ״̬
	//�����һ��
	
	for (int i = 1; i <= n; i++)
	{
		for (int c = 1; c <= cap; c++)
		{
			if (wgt[i-1] > c)
			{
				dp[i][c] = dp[i - 1][c];
			}
			else {

				dp[i][c] = max(dp[i-1][c], dp[i-1][c-wgt[i-1]] + val[i-1]);

			}	
		}
	}
	return dp[n][cap];
}

void testKnapsack()
{
	
	vector<int> wgt = { 10, 20, 30, 40, 50 };
	vector<int> val = { 50, 120, 150, 210, 240 };
	int cap = 50;
	int n = wgt.size();

	// ��������
	int res = knapsack_DFS(wgt, val, n, cap);
	cout << "���������������������Ʒ��ֵΪ " << res << endl;

	// ���仯����
	vector<vector<int>> mem(n + 1, vector<int>(cap + 1, -1));
	res = knapsack_DFSmem(wgt, val, mem, n, cap);
	cout << "���������������������Ʒ��ֵΪ " << res << endl;

	// ��̬�滮
	res = knapsack_DP(wgt, val, cap);
	cout << "���������������������Ʒ��ֵΪ " << res << endl;

	// �ռ��Ż���Ķ�̬�滮
//	res = knapsackDPComp(wgt, val, cap);
	cout << "���������������������Ʒ��ֵΪ " << res << endl;

	return ;
}
