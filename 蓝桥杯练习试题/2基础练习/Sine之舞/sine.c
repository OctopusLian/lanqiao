#include<stdio.h>
void An_Output(int n, int t)
{
	if(n == t)
	{
		printf("sin(%d)", t);
		return ;
	}
	char c;
	c = t % 2 == 1 ? '+' : '-';
	printf("sin(%d%c", t, c);
	An_Output(n, ++t);
	printf(")");
}
void Sn_Output(int n, int t)
{
	//　Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
	if(n == t)
	{
		return ;
	}
	printf("(");
	Sn_Output(n, t+1);
	if(t != n - 1)
	{	
		printf(")");
	}
	An_Output(n - t, 1);
	printf("+%d", t+1);
}
int main()
{
	int n;
	scanf("%d", &n);
	Sn_Output(n, 1);
	if(n!=1)
		printf(")");
	An_Output(n, 1);
	printf("+1\n");
	return 0;
}