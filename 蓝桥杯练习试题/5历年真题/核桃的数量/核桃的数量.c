#include <stdio.h>
#include <stdlib.h>

//最小公倍数
int LCM(int num1,int num2,int num3)
{
	int value=num1;
	while(value%num1!=0||value%num2!=0||value%num3!=0)
	{
		value+=num1;
	}
	return value;
}

int main()
{
	int num1,num2,num3;
	scanf("%d%d%d",&num1,&num2,&num3);
	printf("%d\n",LCM(num1,num2,num3));
	return 0;
}

/*

#include <stdio.h>

int main(int argc, char *argv[]) {
    int a,b,c,i;
    int all;
    scanf("%d %d %d",&a,&b,&c);
    all=a*b*c;
    for(i=1;i<=all;i++)
	{
		if(i%a==0&&i%b==0&&i%c==0)
		{
			printf("%d",i);
			break;
		}
	}
    return 0;
}
*/