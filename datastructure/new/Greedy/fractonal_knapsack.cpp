#include "fractonal_knapsack.h"

double fractionalKnapsack(vector<int> &wgt, vector<int> &val, int cap)
{
	//贪心算法:获取装cap重量的背包能装出的最大价值

	//1.对价值单价排序。从价值高到低开始装，直到装满背包，此时为最大价值。
	// 类比生活中 1kg黄金和1kg石头谁的价值高。

	int n = wgt.size();
	vector<Item> items;
	//构建item
	for (int i = 0; i < n; i++)
	{
		items.emplace_back(Item(wgt[i], val[i]));
	}

	//排序item，价值从高到低
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
			//cap只能装部分item
			maxval += cap * items[i].v / items[i].w;
			break;
		}

	}
	return maxval;
}

void test_fractional_knapsack()
{
	vector<int> wgt = { 10, 20, 30, 40, 50 };
	vector<int> val = { 50, 120, 150, 210, 240 };
	int cap = 50;

	// 贪心算法
	double res = fractionalKnapsack(wgt, val, cap);
	cout << "不超过背包容量的最大物品价值为 " << res << endl;

	return ;
}
