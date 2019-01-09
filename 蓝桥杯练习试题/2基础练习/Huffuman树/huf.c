#include <stdio.h>

typedef struct
{
	int a[100];
	int len;
}huf;

int sum=0;

int del(huf* in,int t)
{
	int i,j;
	for(i=0;i<in->len && in->a[i]!=t;i++);
	for(;i<in->len-1;i++)
		in->a[i]=in->a[i+1];
	in->len--;
	return 1;
}

int add(huf* in,int t)
{
	in->a[in->len]=t;
	in->len++;
}

int find_two_mins(huf* in)
{
	int i,j,t;
	int mina,minb;

	for(i=0;i<in->len-1;i++)
		for(j=i+1;j<in->len;j++)
			if(in->a[i]>in->a[j])
			{
				t=in->a[i];
				in->a[i]=in->a[j];
				in->a[j]=t;
			}
	mina=in->a[0];
	minb=in->a[1];
	del(in,mina);
	del(in,minb);
	add(in,mina+minb);
	return mina+minb;
}

int main()
{
	huf in;
	int i,j,n;
	scanf("%d",&n);
	in.len=n;
	for(i=0;i<n;i++)
		scanf("%d",&in.a[i]);

	while(1)
	{
		if(in.len==2)
		{
			sum=sum+in.a[0]+in.a[1];
			break;
		}
		sum+=find_two_mins(&in);
	}
	printf("%d",sum);

	return 0;
}