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

void testMinPath()
{
	vector<vector<int>> grid = { { 1, 3, 1, 5 },{ 2, 2, 4, 2 },{ 5, 3, 2, 1 },{ 4, 3, 5, 2 } };
	int n = grid.size(), m = grid[0].size();

	// 暴力搜索
	int res = minPathSumDFS(grid, n - 1, m - 1);
	cout << "从左上角到右下角的最小路径和为 " << res << endl;
}
