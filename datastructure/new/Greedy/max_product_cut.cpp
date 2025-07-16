#include "max_product_cut.h"

int maxProductCutting(int n)
{
	if (n <= 3) //边界情况 1，2，3  3 最大切分乘积为(1x2) 2 为 1x1
	{
		return 1 * (n - 1);
	}
	//大于4的需要切分
	int a = n / 3; //切分出多少个3
	int b = n % 3; //余数

	if (b == 0)
	{
		return pow(3, a);
	}
	if (b == 1)
	{
		return	pow(3, a - 1) * 2 * 2;
	}
	if (b == 2)
	{
		return pow(3, a) * 2;
	}
	return -1;
}

void testMaxProductCut()
{
	int n = 6;

	// 贪心算法
	int res = maxProductCutting(n);
	cout << "最大切分乘积为" << res << endl;
}
