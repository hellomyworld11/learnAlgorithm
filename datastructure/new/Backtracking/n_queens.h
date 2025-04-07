#pragma once
#include "../util.h"

void backtrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res, vector<bool> &cols,
	vector<bool> &diags1, vector<bool> &diags2);


vector<vector<vector<string>>> nQueens(int n);

void testNqueens();