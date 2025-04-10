#include "climbing_stairs.h"

void backtrack(vector<int>& steps, vector<int>& choices, int state, int n, vector<vector<int>>& res)
{
	if (state == n)
	{
		res.push_back(steps);
		return;
	}

	for (int i = 0; i < choices.size(); i++)
	{
		int choice = choices[i];
		if (state + choice <= n)  //��֦
		{
			steps.push_back(choice);  //ѡ��
			backtrack(steps, choices, state + choice, n, res);   //����
			steps.pop_back();         //����
		}
	}
}

int climbingStairs_Backtrack(int n, vector<vector<int>>& res)
{
	CountTime time;

	vector<int> choices = { 1, 2 }; //ѡ��
	vector<int> steps;  //����
	int state = 0;  //״̬
//	vector<vector<int>> res; //��¼���������;��岽��
	backtrack(steps, choices, state, n, res);
	return res.size();

}

int dfs(int i)
{
	if (i == 1 || i == 2)
	{
		return i;
	}
		
	return dfs(i - 1) + dfs(i-2);
}

int dfs(int i, vector<int> &memory)
{
	if (i == 1 || i == 2)
	{
		memory[i] = i;
		return i;
	}
	int count = 0;
	if (memory[i - 1] != -1)
	{
		count += memory[i - 1];
	}
	else {
		count += dfs(i - 1, memory);
	}

	if (memory[i - 2] != -1)
	{
		count += memory[i - 2];
	}
	else {
		count += dfs(i - 2, memory);
	}
	memory[i] = count;
	return count;
}

int climbingStairs_dfsmemory(int n)
{
	CountTime time;
	vector<int> memory(n+1, -1);
	return dfs(n, memory);
}

int climbinStairs_dfs(int n)
{
	CountTime time;
	return dfs(n);
}

int climbingStairs_dp(int n)
{
	CountTime time;

	if (n == 1 || n == 2)
	{
		return n;
	}

	int dp1 = 1;
	int dp2 = 2;
	vector<int> res(n+1, -1);
	
	for (int i = 1; i < res.size(); i++)
	{
		if (i == 1 || i == 2)
		{
			res[i] = i;
		}
		else {
			res[i] = res[i - 1] + res[i - 2];
		}
	}

	return res[n];
}

int climbingStairs_dpComp(int n)
{
	if (1 == n || 2 == n)
	{
		return n;
	}
	int pre = 2;
	int prepre = 1;
	for (int i = 3; i <= n; i++)
	{
		int temp = pre;
		pre = pre + prepre;
		prepre = temp;
	}
	return pre;
}

int minCostClimbingStairsDp(vector<int>& cost)
{
	int n = cost.size() - 1;
	if (n == 1 || n == 2)
	{
		return cost[n];
	}

	vector<int> dp(n+1);
	dp[1] = cost[1];
	dp[2] = cost[2];

	for (int i = 3; i <= n ; i++)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}
	return dp[n];
}

int climbingStairsConstraintDP(int n)
{
	if (1 == n || 2 == n)
	{
		return 1;
	}

	vector<vector<int>> dp(n+1, vector<int>(3, 0));
	//1��¥��ʱ��ֻ��1�׷��� 
	dp[1][1] = 1;
	dp[1][2] = 0;
	//2��¥�� ֻ��2�ף���������2��1��
	dp[2][1] = 0;
	dp[2][2] = 1;
	for (int i = 3; i <= n; i++)
	{
		//����һ����1�׵���һ��ʱ�����ϲ�ֻ����2��
		dp[i][1] = dp[i - 1][2];
		//����һ����2�׵���һ��ʱ�����ϲ�������1�׻�2��
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
	}
	return  dp[n][1] + dp[n][2];
}

void testClimbingStairs()
{
	int n = 5;
	vector<vector<int>> ressteps;
	int res = climbingStairs_Backtrack(n, ressteps);
	cout << "���ݷ��� �� " << n << " ��¥�ݹ��� " << res << " �ַ���" << endl;
	res = climbinStairs_dfs(n);
	cout << "dfs����������� �� " << n << " ��¥�ݹ��� " << res << " �ַ���" << endl;
	res = climbingStairs_dfsmemory(n);
	cout << "dfs��ȼ����������� �� " << n << " ��¥�ݹ��� " << res << " �ַ���" << endl;
	res = climbingStairs_dp(n);
	cout << "��̬�滮���� �� " << n << " ��¥�ݹ��� " << res << " �ַ���" << endl;
//	printVectorMatrix(ressteps);
	vector<int> cost = { 0, 1, 10, 1, 1, 1, 10, 1, 1, 10, 1 };
	cout << "����¥�ݵĴ����б�Ϊ ";
	printVector(cost);

	res = minCostClimbingStairsDp(cost);
	cout << "����¥�ݵ���ʹ���Ϊ " << res << endl;

	res = climbingStairsConstraintDP(n);
	cout << "�� " << n << " ��¥�ݹ��� " << res << " �ַ���" << endl;
}
