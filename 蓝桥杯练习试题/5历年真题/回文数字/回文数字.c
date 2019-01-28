#include<stdio.h>
int main()
{
	int n;
	int flag=0;
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			for(k=0;k<=9;k++)
			{
				if(2*i+2*j+k==n)
				{
					printf("%d%d%d%d%d\n",i,j,k,j,i);
					flag=1;
				}
			}
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			for(k=0;k<=9;k++)
			{
				if(2*i+2*j+2*k==n)
				{
					printf("%d%d%d%d%d%d\n",i,j,k,k,j,i);
					flag=1;
				}
			}
	if(flag==0)
		printf("-1");
	return 0;
}

/*
第二种解法

#include<stdio.h>
int main()
{
	int a,b,c;
	int n;
	int flag=-1;   //标志位
	scanf("%d",&n);
	
	for(a=1;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			for(c=0;c<10;c++)
			{
				if(a+b+c+b+a==n)
				{
					flag=1;
					printf("%d%d%d%d%d\n",a,b,c,b,a);
				}
			}
		}
	}

	for(a=1;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			for(c=0;c<10;c++)
			{
				if(a+b+c+c+b+a==n)
				{
					printf("%d%d%d%d%d%d\n",a,b,c,c,b,a);
					flag=1;
				}
			}
		}
	}
	if(flag==-1)
		printf("%d\n",flag);
	return 0;
}


*/