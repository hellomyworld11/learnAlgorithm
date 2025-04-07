#include "subset_sum.h"

void backtrack(vector<int> &state, int target, int total, vector<int> &choices, vector<vector<int>> &res)
{
	if (total == target)
	{
		res.push_back(state);
		return;
	}

	for (int i = 0; i < choices.size(); i++)
	{
		int choice = choices[i];
		if (total + choice > target)
		{
			continue;
		}
		state.push_back(choice);
		backtrack(state, target, total + choice, choices, res);
		state.pop_back();
	}
}



std::vector<std::vector<int>> subsetSumINaive(vector<int> &nums, int target)
{
	vector<int> state;
	vector<vector<int>> res;
	//vector<int> choice;  这里nums就是选择
	backtrack(state, target, 0, nums, res);
	return res;
}

void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
	if (target == 0)
	{
		res.push_back(state);
		return;
	}

	//从start开始，避免了重复元素情况。 因为3，4 已出现，则 4的时候必须往后遍历，而不是4，3
	for (int i = start; i < choices.size(); i++)
	{
		int choice = choices[i];
		if (target - choice < 0)  //后面的肯定也是大于target，故直接结束遍历
		{
			break;
		}

		state.push_back(choice);
		backtrack(state, target-choice, choices, i, res);
		state.pop_back();
	}
}

void backtrack_repeatchoices(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
	if (target == 0)
	{
		res.push_back(state);
		return;
	}

	//从start开始，避免了重复元素情况。 因为3，4 已出现，则 4的时候必须往后遍历，而不是4，3
	// 剪枝二：从 start 开始遍历，避免生成重复子集
	// 剪枝三：从 start 开始遍历，避免重复选择同一元素
	for (int i = start; i < choices.size(); i++)
	{
		int choice = choices[i];
		// 剪枝一：若子集和超过 target ，则直接结束循环
		// 这是因为数组已排序，后边元素更大，子集和一定超过 target
		if (target - choice < 0) 
		{
			break;
		}
		//剪枝四： 如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
		if (i > start && choice == choices[i-1])
		{
			continue;
		}
		state.push_back(choice);
		backtrack(state, target - choice, choices, i+1, res);
		state.pop_back();
	}
}

std::vector<std::vector<int>> subsetSumINaive_norepeat(vector<int> &nums, int target)
{
	vector<int> state;
	vector<vector<int>> res;
	//先从小到大排序,则和大于target的后面的元素不用继续
	std::sort(nums.begin(), nums.end());
	backtrack_repeatchoices(state, target, nums, 0, res);
	return res;
}

void testSubsetsum()
{
	vector<int> nums = { 3, 4, 5 };
	int target = 9;

	
	vector<vector<int>> res = subsetSumINaive_norepeat(nums, target);

	cout << "输入数组 nums = ";
	printVector(nums);
	cout << "target = " << target << endl;
	cout << "所有和等于 " << target << " 的子集 res = " << endl;
	printVectorMatrix(res);
}
