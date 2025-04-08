#include "climbing_stairs.h"


void backtrack(vector<int>& steps, vector<int>& choices, int state, int n, vector<vector<int>>& res)
{
	if (state == n)
	{
		res.push_back();
	}
}

int climbingStairs_Backtrack(int n)
{
	vector<int> choices = { 1, 2 };
	int state = 0;
	vector<vector<int>> res; //��¼���������;��岽��
	backtrack(choices, state, n, res);
	return res.size();
}

void testClimbingStairs()
{
	int n = 9;

	int res = climbingStairs_Backtrack(n);
	cout << "�� " << n << " ��¥�ݹ��� " << res << " �ַ���" << endl;

}
