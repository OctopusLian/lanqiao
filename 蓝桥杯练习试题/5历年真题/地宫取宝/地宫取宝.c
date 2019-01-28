#include<stdio.h>
#include<string.h>

#define N 55
#define MOD  1000000007

int map[55][55];
int dp[55][55][15][15];

int main(void)
{
	int n, m, k;
	int i, j, c, val, aMax;
	scanf("%d%d%d", &n, &m, &k);
	aMax = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
//			map[i][j]++;
			if(aMax < map[i][j])
			{
				aMax = map[i][j];
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[1][1][0][0] = 1;
	dp[1][1][1][map[1][1]] = 1;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			dp[i][j][0][0] += dp[i][j - 1][0][0] + dp[i - 1][j][0][0];
			dp[i][j][0][0] %= MOD;
			for(c = 1; c <= k; c++)
			{
				for(val = 0; val <= aMax; val++)
				{
					dp[i][j][c][val] += dp[i][j - 1][c][val] + dp[i - 1][j][c][val];
					dp[i][j][c][val] %= MOD;
				}
				if(c == 1)
				{
					dp[i][j][1][map[i][j]] += dp[i][j - 1][0][0];
					dp[i][j][1][map[i][j]] %= MOD;
					dp[i][j][1][map[i][j]] += dp[i - 1][j][0][0];
					dp[i][j][1][map[i][j]] %= MOD;
				}
				else
				{
					for(val = 0; val < map[i][j]; val++)
					{
						dp[i][j][c][map[i][j]] += dp[i][j - 1][c - 1][val];
						dp[i][j][c][map[i][j]] %= MOD;
						dp[i][j][c][map[i][j]] += dp[i - 1][j][c - 1][val];
						dp[i][j][c][map[i][j]] %= MOD;
					}
				}
			}
		}
	}
	
	int sum = 0;
	for(i = 0; i <= aMax; i++)
	{
		sum += dp[n][m][k][i];
		sum %= MOD;
	}
	printf("%d", sum);
	return 0;
}