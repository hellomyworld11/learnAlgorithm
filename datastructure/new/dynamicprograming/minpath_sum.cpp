#include "minpath_sum.h"

int minPathSumDFS(vector<vector<int>> &grid, int i, int j)
{
	if (i == 0 && j == 0)
	{
		return grid[0][0];
	}

	if (i < 0 || j < 0)
	{
		return INT_MAX;
	}

	int up = minPathSumDFS(grid, i - 1, j);
	int left = minPathSumDFS(grid, i, j - 1);
	int minpath = min(up, left) ;
	return (minpath != INT_MAX) ? minpath + grid[i][j] : INT_MAX;
}

int minPathSumDFSMem(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j)
{
	if (i == 0 && j == 0)
	{
		return grid[0][0];
	}

	if (i < 0 || j < 0)
	{
		return INT_MAX;
	}

	if (mem[i][j] != -1)
	{
		return mem[i][j];
	}
	int up = minPathSumDFSMem(grid, mem, i-1, j);
	int left = minPathSumDFSMem(grid, mem, i, j - 1);
	int minpath = min(up, left);
	mem[i][j] = minpath != INT_MAX ? minpath + grid[i][j] : INT_MAX;
	return mem[i][j];
}

int minPathSumDP(vector<vector<int>> &grid, int row, int col)
{
	if (row == 0 && col == 0)
	{
		return grid[0][0];
	}

	int rows = grid.size();
	int cols = grid[0].size();

	vector<vector<int>> dps(rows, vector<int>(cols));
	dps[0][0] = grid[0][0];

	//首行
	for (int i = 1; i < cols; i++)
	{
		dps[0][i] = dps[0][i - 1] + grid[0][i];
	}

	//首列
	for (int j = 1; j < rows; j++)
	{
		dps[j][0] = dps[j-1][0] + grid[j][0];
	}

	//其余需要比较最小路径
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			dps[i][j] = min(dps[i - 1][j], dps[i][j - 1]) + grid[i][j];
		}
	}

	return dps[row][col];
}

int minPathSumDPComp(vector<vector<int>> &grid, int row, int col)
{
	int n = grid.size(), m = grid[0].size();
	// 初始化 dp 表
	vector<int> dp(m);
	// 状态转移：首行
	dp[0] = grid[0][0];
	for (int j = 1; j < m; j++) {
		dp[j] = dp[j - 1] + grid[0][j];
	}
	// 状态转移：其余行
	for (int i = 1; i < n; i++) {
		// 状态转移：首列
		dp[0] = dp[0] + grid[i][0];
		// 状态转移：其余列
		for (int j = 1; j < m; j++) {
			dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
		}
	}
	return dp[m - 1];

void testMinPath()
{
	vector<vector<int>> grid = { { 1, 3, 1, 5 },{ 2, 2, 4, 2 },{ 5, 3, 2, 1 },{ 4, 3, 5, 2 } };
	int n = grid.size(), m = grid[0].size();

	// 暴力搜索
	int res = minPathSumDFS(grid, n - 1, m - 1);
	cout << "暴力搜索 从左上角到右下角的最小路径和为 " << res << endl;

	res = minPathSumDP(grid, n - 1, m - 1);
	cout << "动态规划 从左上角到右下角的最小路径和为 " << res << endl;
}
