//夺宝奇兵
#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int N,i,j;
    int a[101][101]={0};
    int f[101][10]={0};
    
    scanf("%d",&N);
    
    for(i=1;i<=N;i++)
       for(j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
	
	 for(i=N;i>=0;i--)
		for(j=1;j<=i;j++)
		{
			f[i][j]=max( f[i+1][j],f[i+1][j+1] )+a[i][j];
		}
     printf("%d\n",f[1][1]);
    return 0;
}
