#include <stdio.h>
#include <string.h>
#include <math.h>
int abmax(int a1, int a2, int a3)
{
	int max = abs(a1);
	if (abs(a2) > max)
		max = abs(a2);
	if (abs(a3) > max)
		max = abs(a3);
	return max;
}

int main()
{
	int t = 0;
	int i = 0, j = 0;
	int n[3];
	int buf[3][100000];
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n[i]);
		for (j = 0; j < n[i]; j++)
		{
			scanf("%d", &buf[i][j]);
		}
	}

	for (i = 0; i < t; i++)
	{
		int max_p = 0;
		while (1)
		{
			int flag = 0;
			int max = 0;
			for (j = 1; j < n[i] - 1; j++)
			{
				int tmp[3];
				int max1, max2;
				tmp[0] = buf[i][j - 1] + buf[i][j];
				tmp[1] = -1 * buf[i][j];
				tmp[2] = buf[i][j + 1] + buf[i][j];
				max1 = abmax(buf[i][j - 1], buf[i][j], buf[i][j + 1]);
				max2 = abmax(tmp[0], tmp[1], tmp[2]);
				if (max1 >= max2)
				{
					buf[i][j - 1] = tmp[0];
					buf[i][j] = tmp[1];
					buf[i][j + 1] = tmp[2];
					flag = 1;
				}
			}

			for (j = 0; j < n[i]; j++)
			{
				if (abs(buf[i][j]) > max)
					max = abs(buf[i][j]);
			}

			if (flag == 0 || max_p == max)
			{
				printf("%d\n", max);
				break;
			}
			else
			{
				max_p = max;
			}
			
		}
	}
	return 0;
}
