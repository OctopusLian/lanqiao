#include<stdio.h>
void f(int a)
{
	if(a==0)printf("%c",'A');
	else 
	{
		f(a-1);
		printf("%c",a+'A');
		f(a-1);
	}
}
int main()
{
	int a;scanf("%d",&a);f(a-1);printf("\n");
	return 0;
}