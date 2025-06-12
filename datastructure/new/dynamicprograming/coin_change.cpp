#include "coin_change.h"

int coinChange_DP(vector<int> &coins, int amt)
{
	int n = coins.size();
	int MAX = amt + 1;
	vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));

	for (int a = 1; a <= amt; a++)
	{
		dp[0][a] = MAX;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int a = 1; a <= amt; a++)
		{
			if (coins[i-1] > a)
			{
				dp[i][a] = dp[i - 1][a];
			}
			else {
				dp[i][a] = min(dp[i-1][a], dp[i][a-coins[i-1]] + 1);
			}
		}
	}

	return dp[n][amt] != MAX ? dp[n][amt] : -1;
}

void test_coin_change()
{
	vector<int> coins = { 1, 2, 5 };
	int amt = 4;

	// 动态规划
	int res = coinChange_DP(coins, amt);
	cout << "凑到目标金额所需的最少硬币数量为 " << res << endl;
}
