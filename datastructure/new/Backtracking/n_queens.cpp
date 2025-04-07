#include "n_queens.h"

void backtrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res, vector<bool> &cols, vector<bool> &diags1, vector<bool> &diags2)
{
	if (row == n)
	{
		res.push_back(state);
		return;
	}

	for (int col = 0; col < n; col++)
	{
		//主对角线 次对角线
		int diag1 = row - col + n - 1; //主对角线索引不能越界 为0 到 2*n-1
		int diag2 = row + col;
		//剪枝 行列，对角线上都没有棋子，则可以落子
		if (!cols[col] && !diags1[diag1] && !diags2[diag2])
		{
			//尝试
			state[row][col] = "Q";
			cols[col] = true;
			diags1[diag1] = true;
			diags2[diag2] = true;
			//第row行已放置，接下来考虑第row+1行
			backtrack(row+1, n, state, res, cols, diags1, diags2);
			//回退
			state[row][col] = "#";
			cols[col] = false;
			diags1[diag1] = false;
			diags2[diag2] = false;
		}
	}
}

std::vector<std::vector<std::vector<std::string>>> nQueens(int n)
{
	vector<vector<string>> state(n, vector<string>(n, "#"));
	vector<bool> cols(n, false);
	vector<bool> diags1(2*n-1, false);  //4*4的 棋盘，对角线有2*n-1条
	vector<bool> diags2(2*n-1, false);
	vector<vector<vector<string>>> res;
	backtrack(0, n, state, res, cols, diags1, diags2);
	return res;
}

void testNqueens()
{
	int n = 4;
	vector<vector<vector<string>>> res = nQueens(n);
	//时间复杂度O(n!n2) 控件O（n2）
	cout << "输入棋盘长宽为 " << n << endl;
	cout << "皇后放置方案共有 " << res.size() << " 种" << endl;
	for (const vector<vector<string>> &state : res) {
		cout << "--------------------" << endl;
		for (const vector<string> &row : state) {
			printVector(row);
		}
	}
}
