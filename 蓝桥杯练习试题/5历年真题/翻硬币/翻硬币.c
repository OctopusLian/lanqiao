#include <stdio.h>
#include <stdlib.h>

int turn(char a[], char b[])
{
	int i;
	int n = 0;
	for(i = 0;a[i]!='\0';i++) 
	{
		if(a[i] == b[i]) 
		{
			continue;
		} 
		else 
		{
			b[i+1]=(b[i+1]=='*'?'o':'*');
			n++;
		}
	}
	return n;
}

int main(void)
{
	char a[1000];
	char b[1000];
	gets(a);
	gets(b);
	printf("%d\n", turn(a, b));
	return 0;
}
