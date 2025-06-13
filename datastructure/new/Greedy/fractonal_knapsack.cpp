#include "fractonal_knapsack.h"

double fractionalKnapsack(vector<int> &wgt, vector<int> &val, int cap)
{
	//̰���㷨:��ȡװcap�����ı�����װ��������ֵ

	//1.�Լ�ֵ�������򡣴Ӽ�ֵ�ߵ��Ϳ�ʼװ��ֱ��װ����������ʱΪ����ֵ��
	// ��������� 1kg�ƽ��1kgʯͷ˭�ļ�ֵ�ߡ�

	int n = wgt.size();
	vector<Item> items;
	//����item
	for (int i = 0; i < n; i++)
	{
		items.emplace_back(Item(wgt[i], val[i]));
	}

	//����item����ֵ�Ӹߵ���
	sort(items.begin(), items.end(), [&](Item& lhs, Item& rhs) {
		return lhs.v / lhs.w > rhs.v / rhs.w;
	});

	double maxval = 0;
	for (int i = 0; i < items.size(); i++)
	{
		if (cap >= items[i].w)
		{
			maxval += items[i].v;
			cap -= items[i].w;
		}
		else {
			//capֻ��װ����item
			maxval += cap * items[i].v / items[i].w;
			break;
		}

	}
	return maxval;
}
