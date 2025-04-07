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
	//vector<int> choice;  ����nums����ѡ��
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

	//��start��ʼ���������ظ�Ԫ������� ��Ϊ3��4 �ѳ��֣��� 4��ʱ��������������������4��3
	for (int i = start; i < choices.size(); i++)
	{
		int choice = choices[i];
		if (target - choice < 0)  //����Ŀ϶�Ҳ�Ǵ���target����ֱ�ӽ�������
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

	//��start��ʼ���������ظ�Ԫ������� ��Ϊ3��4 �ѳ��֣��� 4��ʱ��������������������4��3
	// ��֦������ start ��ʼ���������������ظ��Ӽ�
	// ��֦������ start ��ʼ�����������ظ�ѡ��ͬһԪ��
	for (int i = start; i < choices.size(); i++)
	{
		int choice = choices[i];
		// ��֦һ�����Ӽ��ͳ��� target ����ֱ�ӽ���ѭ��
		// ������Ϊ���������򣬺��Ԫ�ظ����Ӽ���һ������ target
		if (target - choice < 0) 
		{
			break;
		}
		//��֦�ģ� �����Ԫ�������Ԫ����ȣ�˵����������֧�ظ���ֱ������
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
	//�ȴ�С��������,��ʹ���target�ĺ����Ԫ�ز��ü���
	std::sort(nums.begin(), nums.end());
	backtrack_repeatchoices(state, target, nums, 0, res);
	return res;
}

void testSubsetsum()
{
	vector<int> nums = { 3, 4, 5 };
	int target = 9;

	
	vector<vector<int>> res = subsetSumINaive_norepeat(nums, target);

	cout << "�������� nums = ";
	printVector(nums);
	cout << "target = " << target << endl;
	cout << "���к͵��� " << target << " ���Ӽ� res = " << endl;
	printVectorMatrix(res);
}
