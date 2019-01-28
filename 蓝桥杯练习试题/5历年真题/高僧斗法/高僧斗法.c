#include <stdio.h> 
int main()
{
	int a[105],b[105],i=0,j,k,count,sum;
	char c;
	while(1)
	{
		scanf("%d%c",&a[i++],&c);
		if(c=='\n')
			break;
	}
	count=i;
	for(i = 0;i < count-1;i++)
		b[i]=a[i+1]-a[i]-1;
	b[count-1]=0;
	sum=b[0];
	for(i = 2;i < count;i = i+2)
		sum^=b[i];
	if(sum == 0)
		printf("-1\n");
	else
	{
		for(i = 0;i < count;i++)
			for(j = 1;j <= b[i];j++)
			{
				b[i] -= j;
				if(i!=0)
					b[i-1]+=j;
				sum = b[0];
				for(k = 2;k < count;k = k+2)
					sum ^= b[k];
				if(sum == 0)
				{
					printf("%d %d\n",a[i],a[i]+j);
					break;
				}
				b[i] += j;
				if(i != 0)
					b[i-1] -= j;
			}
	}
	return 0;
}
