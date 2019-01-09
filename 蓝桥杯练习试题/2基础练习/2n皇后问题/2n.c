#include<stdio.h>

int sum=0;

int p(int n,int x,int y,int m[][8],int s)
{
	int i,j;
	for(i=x-1;i>=0;i--)
	{
		if(m[i][y]==s)return 0;
	}
	for(i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
	{
		if(m[i][j]==s)return 0;
	}
	for(i=x-1,j=y+1;i>=0&&j<n;i--,j++)
	{
		if(m[i][j]==s)return 0;
	}
	return 1;
}

int h(int n,int x,int m[][8],int s)
{
	int i;
	if(x==n)
	{
		if(s==2)h(n,0,m,3);
		else sum++;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(m[x][i]!=1)continue;
		if(p(n,x,i,m,s))m[x][i]=s;
		else continue;
		h(n,x+1,m,s);
		m[x][i]=1;
	}
	return 0;
}

int main()
{
	int n,m[8][8],i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	h(n,0,m,2);
	printf("%d",sum);

	return 0;
}