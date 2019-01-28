#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 26

//输出
void Print(char matrix[MAXSIZE][MAXSIZE],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%c",matrix[i][j]);
		}
		printf("\n");
	}
}

//实现字母图形
void Drawing(int n,int m)
{
	int i,j;
	int point=0;
	char str;
	char matrix[MAXSIZE][MAXSIZE];
	for(i=0;i<n;i++)
	{
		str='A';
		for(j=i;j<m;j++)
		{
			matrix[i][j]=str++;
		}
		str='A';
		for(j=i-1;j>=0;j--)
		{
			matrix[i][j]=++str;
		}
	}
	Print(matrix,n,m);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Drawing(n,m);
	return 0;
}