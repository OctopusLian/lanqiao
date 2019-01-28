#include <stdio.h>
#include <stdlib.h>

typedef struct Interval
{
	int pre;
	int rear;
	int satisfy;
}Interval;
Interval interval[7][5];
int count=0;

//初始化
void Init()
{
	int i,j;
	int value;
	for(i=1;i<7;i++)
	{
		value=i;
		for(j=1;j<5;j++)
		{
			interval[i][j].pre=value++;
			interval[i][j].rear=value;
		}
	}
}

//数组初始化为0
void InitZero(int *sign)
{
	int i;
	sign[0]=1;
	for(i=1;i<10;i++)
	{
		sign[i]=0;
	}
}

//将一个数的各个位上拆分，并在相应的位上赋值1
int Split(int *sign,int value)
{
	int index;
	while(value)
	{
		index=value%10;
		if(sign[index]==0) sign[index]=1;
		else return 1;
		value/=10;
	}
	return 0;
}

//计算一个数的位数
int CountBit(int value)
{
	int n=0;
	while(value)
	{
		n++;
		value/=10;
	}
	return n;
}

//将一个整型数组转换成一个整数
int CreateInteger(int *data,int n)
{
	int i;
	int value=0;
	for(i=0;i<n;i++)
	{
		value=value*10+data[i];
	}
	return value;
}

//检查是否每个数都用到
int Check(int *sign)
{
	int i;
	for(i=1;i<10;i++)
	{
		if(sign[i]==0) return 0;
	}
	return 1;
}

//复制
void Copy(int *sign,int *temp_sign)
{
	int i;
	for(i=0;i<10;i++)
	{
		temp_sign[i]=sign[i];
	}
}
//创建一个n位数的整数
void CreateNBitNumber(int *sign,int *data,int n,int m,int value,int value3)
{
	if(n==m)
	{
		int value1=CreateInteger(data,n);
		int value2=value1*value;
		int temp_sign[10];
		Copy(sign,temp_sign);
		if(!Split(temp_sign,value2) && Check(temp_sign))
		{
			count++;
		}
	}
	else
	{
		int i;
		for(i=1;i<10;i++)
		{
			if(sign[i]==0)
			{
				sign[i]=1;
				data[m]=i;
				CreateNBitNumber(sign,data,n,m+1,value,value3);
				sign[i]=0;
			}
		}
	}
}

//求出解
void Create(int value)
{
	int i,j;
	int sign[10];
	int result;
	int result_n;
	int n;
	for(i=3;i<value;i++)
	{
		InitZero(sign);
		if(Split(sign,i)) continue;
		result=value-i;
		result_n=CountBit(result);
		n=CountBit(i);
		for(j=1;j<5;j++)
		{
			if( ((interval[result_n][j].pre+j)==(9-n)) || ((interval[result_n][j].rear+j)==(9-n)))
			{
				int data[5];
				CreateNBitNumber(sign,data,j,0,result,i);
			}
		}
	}
}

int main()
{
	int value;
	scanf("%d",&value);
	Init();
	Create(value);
	printf("%d\n",count);
	return 0;
}
