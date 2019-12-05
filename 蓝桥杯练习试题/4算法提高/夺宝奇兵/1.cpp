#include <cstdlib>
#include <iostream>
#include <cstdio>
//#include <windows.h>

using namespace std;

int dp[101][101];

int maxx(int a, int b)
{
    return a>b?a:b;
}

int main()
{
    int N, i, j;
    scanf("%d", &N);
    
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= i; j++)
        scanf("%d", &dp[i][j]);
    }
    
    for(i = N-1; i >= 1; i--)
    {
        for(j = 1; j <= N-1; j++)
        dp[i][j] = maxx(dp[i+1][j], dp[i+1][j+1])+dp[i][j];
    }
    printf("%d\n", dp[1][1]);
    //system("pause");
    return 0;
}
