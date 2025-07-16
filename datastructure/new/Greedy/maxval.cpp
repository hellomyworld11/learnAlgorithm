#include "maxval.h"

int maxval(vector<int> hts)
{
	int size = hts.size();
	int i = 0;
	int j = size - 1;
	int maxval = (j-i) * min(hts[i], hts[j]);
	//贪心策略 : 为了保证面积只增不减,只移动短板，不移动高板，并记录最大容量
	double val = 0;
	while (i < j)
	{
		//移动短板
		if (hts[i] < hts[j])
		{
			i++;
		}
		else {
			j--;
		}
		val = (j - i) * min(hts[i], hts[j]);
		//获取容量
		maxval = maxval > val ? maxval : val;
	} 
	return maxval;
}

void testMaxval()
{
	vector<int> ht = { 3, 8, 5, 2, 7, 7, 3, 4 };

	// 贪心算法
	int res = maxval(ht);
	cout << "最大容量为 " << res << endl;

	return ;
}
