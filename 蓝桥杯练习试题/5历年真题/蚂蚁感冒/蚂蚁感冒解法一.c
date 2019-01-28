#include<stdio.h>

int n,a[50],b[110];


void work()
{
	for(int i=1 ; i<n ; i++)
	{
		if(a[i]>0)
		{
			b[a[i]] = 1;
		}
		else
		{
			b[-a[i]] = -1;
		}
	}
	int ans=1,v=a[0];
	bool flag=false;
	if(v>0)
	{
		for(int i=v+1 ; i<110 ; i++)
		{
			if(b[i]<0)
			{
				ans++;
				flag = true;
			}
		}
	}
	else
	{
		for(int i=-v-1 ; i>0 ; i--)
		{
			if(b[i]>0)
			{
				ans++;
				flag = true;
			}
		}
	}
	if(flag)
	{

		if(v<0)
		{
			for(int i=-v+1 ; i<110 ; i++)
			{
				if(b[i]<0)
				{
					ans++;
					flag = true;
				}
			}
		}
		else
		{
			for(int i=v-1 ; i>0 ; i--)
			{
				if(b[i]>0)
				{
					ans++;
					flag = true;
				}
			}
		}
	}
	printf("%d\n",ans);
}


void init()
{
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
}


int main()
{
	init();
	work();
	return 0;
}