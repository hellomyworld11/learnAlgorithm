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
		if (state + choice <= n)  //剪枝
		{
			steps.push_back(choice);  //选择
			backtrack(steps, choices, state + choice, n, res);   //回溯
			steps.pop_back();         //回退
		}
	}
}

int climbingStairs_Backtrack(int n, vector<vector<int>>& res)
{
	CountTime time;

	vector<int> choices = { 1, 2 }; //选择
	vector<int> steps;  //步骤
	int state = 0;  //状态
//	vector<vector<int>> res; //记录方案个数和具体步骤
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
	//1阶楼梯时，只有1阶方法 
	dp[1][1] = 1;
	dp[1][2] = 0;
	//2阶楼梯 只能2阶，不能连续2个1阶
	dp[2][1] = 0;
	dp[2][2] = 1;
	for (int i = 3; i <= n; i++)
	{
		//当上一步爬1阶到这一层时，上上步只能爬2阶
		dp[i][1] = dp[i - 1][2];
		//当上一步爬2阶到这一层时，上上步可以爬1阶或2阶
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
	}
	return  dp[n][1] + dp[n][2];
}

void testClimbingStairs()
{
	int n = 5;
	vector<vector<int>> ressteps;
	int res = climbingStairs_Backtrack(n, ressteps);
	cout << "回溯法： 爬 " << n << " 阶楼梯共有 " << res << " 种方案" << endl;
	res = climbinStairs_dfs(n);
	cout << "dfs深度搜索法： 爬 " << n << " 阶楼梯共有 " << res << " 种方案" << endl;
	res = climbingStairs_dfsmemory(n);
	cout << "dfs深度记忆搜索法： 爬 " << n << " 阶楼梯共有 " << res << " 种方案" << endl;
	res = climbingStairs_dp(n);
	cout << "动态规划法： 爬 " << n << " 阶楼梯共有 " << res << " 种方案" << endl;
//	printVectorMatrix(ressteps);
	vector<int> cost = { 0, 1, 10, 1, 1, 1, 10, 1, 1, 10, 1 };
	cout << "输入楼梯的代价列表为 ";
	printVector(cost);

	res = minCostClimbingStairsDp(cost);
	cout << "爬完楼梯的最低代价为 " << res << endl;

	res = climbingStairsConstraintDP(n);
	cout << "爬 " << n << " 阶楼梯共有 " << res << " 种方案" << endl;
}
