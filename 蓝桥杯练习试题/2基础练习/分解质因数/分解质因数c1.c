#include <stdio.h>
#define N 10000//筛法，求1万以内的所有素数 
int p[N];
int main()
{
	int i,j,a,b,t;
	for(i=2;i<N/2;i++)
	{
		if(p[i]) continue;//合数不参加筛法 
		for(j=2*i;j<=N;j+=i)
		{
			p[j]=1;
		}
	}
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		t=i;
		printf("%d=",t);
		while(t)
		{
			for(j=2;j*j<=t;j++)
			{
				if(!p[j]&&!(t%j))
				{	
					printf("%d*",j); 
					t/=j;
					break;
				}
			}
			if(j*j>t) 
			{
				printf("%d",t);
				break;
			}
		}
		printf("\n");
	}	
	return 0;
}