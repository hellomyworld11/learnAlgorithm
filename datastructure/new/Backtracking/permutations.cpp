#include "permutations.h"

std::vector<std::vector<int>> permutationsI(vector<int> nums)
{	
	vector<vector<int>> res;
	vector<int> state;
	vector<bool> selected = { false, false, false };
	//backtrack(state, nums, selected, res);
	backtrack_repeat(state, nums, selected, res);
	return res;
}

void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
	if (state.size() == choices.size())
	{
		res.push_back(state);
		return;	
	}
	for (int i = 0; i < choices.size(); i++)
	{
		if (!selected[i])
		{
			state.push_back(choices[i]);
			selected[i] = true;
			backtrack(state, choices, selected, res);
			state.pop_back();
			selected[i] = false;
		}
	}
}

void backtrack_repeat(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
	if (state.size() == choices.size())
	{
		res.push_back(state);
		return;
	}
	unordered_set<int> repeatmap; //1,1,3 �� ֻ��Ҫ1��3���л��ݣ��������ظ�Ԫ���ظ�ѡ��
	for (int i = 0; i < choices.size(); i++)
	{
		int choice = choices[i];
		if (!selected[i] && repeatmap.find(choice) == repeatmap.end())
		{
			repeatmap.emplace(choice);
			state.push_back(choice);
			selected[i] = true;
			backtrack_repeat(state, choices, selected, res);
			state.pop_back();
			selected[i] = false;
		}
	}
}

void testPermutations()
{
	vector<int> nums = { 1, 1, 3 };

	vector<vector<int>> res = permutationsI(nums);

	cout << "�������� nums = ";
	printVector(nums);
	cout << "�������� res = ";
	printVectorMatrix(res);
}
