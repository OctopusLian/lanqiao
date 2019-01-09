#include <stdio.h>
#include <stdlib.h>
char data[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//输出
void Print(char *num,int n)
{
	int i;
	for(i=n-1;i>=0;i--) printf("%c",num[i]);
	printf("\0");
	printf("\n");
}

//将十六进制数转换为十进制数
int Transform(char *num,long long value)
{
	int n=0;
	while(value>=16)
	{
		num[n++]=data[value%16];
		value/=16;
	}
	num[n++]=data[value%16];
	return n;
}

int main()
{
	long long value;
	char num[10];
	int n;
	scanf("%I64d",&value);
	n=Transform(num,value);
	Print(num,n);
	return 0;
}
