#include <stdio.h>
#include <stdlib.h>
#define N 1050
int a[N]; //存放输入数据
int s[N]; //虚拟石子
int total = 0;
int flag= 0;
int i,j;

int main()
{
	do
	{
		scanf("%d",&a[total++]);
		if(total%2==0)
			s[total/2] = a[total-1]-a[total-2]-1;
	}while(getchar()!='\n');

	for(i=1;i<=total/2;i++)
	{
		flag^=s[i];
	}
	//一开始就处于N态
	if(!flag) printf("-1");
	else
	{
		for(i=1;i<=total/2;i++)//从最小的开始遍历
		{
			int temp = s[i];
			//左边上移减少数量
			while(s[i]--)
			{
				flag = 0;
				for(j=1;j<=total/2;j++) //再检测
					flag^=s[j];
				//把对手变成p态!
				if(flag==0)
				{
					//第i个移动i步(移动到哪里)
					//应该是从哪个位置移到哪个位置 跟哪个小和尚没关系
					printf("%d %d\n",a[i*2-2],a[i*2-2]+temp-s[i]);
					exit(0);
				}
			}
			s[i] = temp;

			//右边上移增加数量
			while(s[i]-temp <a[i*2]-a[2*i-1]-1)
			{
				s[i]++;
				flag = 0;
				for(j=1;j<=total/2;j++) //再检测
					flag^=s[j];
				if(flag==0)
				{
					printf("%d %d\n",a[i*2-1],a[i*2-1]+s[i]-temp);
					exit(0);
				}
			}
			s[i]=temp;
		}
	}
	return 0;
}