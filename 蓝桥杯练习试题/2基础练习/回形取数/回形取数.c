#include <stdio.h>
#include <string.h>

#define MAX_N 200
int m,n;
int a[MAX_N][MAX_N],b[MAX_N][MAX_N];
int s=0;

void solve(int i,int j)
{
	if(i<m && i>=0 && j<n && j>=0 && b[i][j] == 0)
	{
		printf("%d ",a[i][j]);
		b[i][j] = 1;
	
	}
	else
	{
		s++;
		return ;
	}
	if(s%4 == 0)
	solve(i+1,j);
	if(s%4 == 1)
	solve(i,j+1);
	if(s%4 == 2)
	solve(i-1,j);
	if(s%4 == 3)
	solve(i,j-1);
	if(s%4 == 0)
	solve(i+1,j);
	if(s%4 == 1)
	solve(i,j+1);
	if(s%4 == 2)
	solve(i-1,j);
	if(s%4 == 3)
	solve(i,j-1);

	return ;
}

int main()
{
	memset(b,0,sizeof(b));
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	solve(0,0);
	puts("");
	return 0;
}