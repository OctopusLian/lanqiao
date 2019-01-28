#include <stdio.h>
#include <malloc.h>
int count=0;
void f(int n,int *m)
{
	int j,temp=m[0];
	for(j=n-1;j>0;j--)
		m[(j+1)%n]+=(m[j]/=2);
	m[1]+=temp/2;
	m[0]-=temp/2;
	for(j=0;j<n;j++)
	{
		if(m[j]%2!=0)
		{
			 m[j]++;
			 count++;
		}
	}
}
int jisuan(int n,int *m)
{
	int j;
	for(j=0;j<n-1;j++)
		if(m[j]!=m[j+1]) return 0;
	return 1;
}
int main()
{
	int n,j;
	scanf("%d",&n);
	int *m=(int*)malloc(sizeof(int)*n);
	for(j=0;j<n;j++)
		scanf("%d",&m[j]);
	do
	{
		f(n,m);
	}
	while(jisuan(n,m)!=1);
	printf("%d",count);
	return 0;
}