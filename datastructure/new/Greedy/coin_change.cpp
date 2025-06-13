#include "coin_change.h"

int coinChangeGreedy(vector<int> &coins, int amt)
{
	int i = coins.size()-1;
	int count = 0;
	while (amt > 0)
	{
		while (i > 0 && coins[i] > amt)
		{
			i--;
		}
		amt -= coins[i];
		count++;
	}
	return amt == 0 ? count : -1;
}



void test_coinChange_greedy()
{
	vector<int> coins = { 1, 20, 50 };
	int amt = 60;
	int res = coinChangeGreedy(coins, amt);
	cout << "\ncoins = ";
	printVector(coins);
	cout << "amt = " << amt << endl;
	cout << "�յ� " << amt << " ���������Ӳ������Ϊ " << res << endl;
	cout << "ʵ������Ҫ����������Ϊ 3 ���� 20 + 20 + 20" << endl;
}
