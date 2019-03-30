#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int m = 0, n = 0;
	int buf[200000];
	int sum1 = 0, sum2 = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m + n + 1; i++)
		scanf("%d", &buf[i]);
	for (int i = 0; i < m + n; i++)
	{
		for (int j = 0; j < m + n - i; j++)
		{
			if (buf[j]>buf[j + 1])
			{
				int t = 0;
				t = buf[j];
				buf[j] = buf[j + 1];
				buf[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < m; i++)
		sum1 += buf[i];
	for (int i = m; i < n + m + 1; i++)
		sum2 += buf[i];
	printf("%d\n", sum2 - sum1);
	return 0;
}