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
		//���Խ��� �ζԽ���
		int diag1 = row - col + n - 1; //���Խ�����������Խ�� Ϊ0 �� 2*n-1
		int diag2 = row + col;
		//��֦ ���У��Խ����϶�û�����ӣ����������
		if (!cols[col] && !diags1[diag1] && !diags2[diag2])
		{
			//����
			state[row][col] = "Q";
			cols[col] = true;
			diags1[diag1] = true;
			diags2[diag2] = true;
			//��row���ѷ��ã����������ǵ�row+1��
			backtrack(row+1, n, state, res, cols, diags1, diags2);
			//����
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
	vector<bool> diags1(2*n-1, false);  //4*4�� ���̣��Խ�����2*n-1��
	vector<bool> diags2(2*n-1, false);
	vector<vector<vector<string>>> res;
	backtrack(0, n, state, res, cols, diags1, diags2);
	return res;
}

void testNqueens()
{
	int n = 4;
	vector<vector<vector<string>>> res = nQueens(n);
	//ʱ�临�Ӷ�O(n!n2) �ؼ�O��n2��
	cout << "�������̳���Ϊ " << n << endl;
	cout << "�ʺ���÷������� " << res.size() << " ��" << endl;
	for (const vector<vector<string>> &state : res) {
		cout << "--------------------" << endl;
		for (const vector<string> &row : state) {
			printVector(row);
		}
	}
}
