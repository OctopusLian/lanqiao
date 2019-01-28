#include <stdio.h>
#define MAXN 40
int n;
int a[MAXN][MAXN];
int main()
{
    int i, j;
    scanf("%d", &n);
    a[0][0] = 1;
    for (i = 0; i < n; ++i)
    {
        a[i][0] = a[i][i] = 1;
        for (j = 1; j < i; ++j)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j <= i; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}