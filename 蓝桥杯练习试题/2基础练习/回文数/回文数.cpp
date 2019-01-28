#include<stdio.h>
int main()
{
	for(int i1=1;i1<10;i1++)
	{
		for(int i2=0;i2<10;i2++)
		{
			for(int i3=0;i3<10;i3++)
			{
				for(int i4=0;i4<10;i4++)
				{
					if(i1==i4 && i2==i3)
					printf("%d%d%d%d\n",i1,i2,i3,i4);
				}
				
			}
		}
	}
	return 0;
}