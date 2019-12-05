#include <stdio.h>
void print(int n)
{
	if(n==10) return ;
	int i,j;
	printf("%d ",n);
	for(i=1;i<=n;i++)
	printf("%d ",n*i);
	printf("\n"); 
	print(n+1);
}

int main()
{
printf("Nine-by-nine Multiplication Table\n");
printf("--------------------------------------\n");
printf("1 2 3 4 5 6 7 8 9\n");
printf("--------------------------------------\n");
print(1);
printf("--------------------------------------");
	return 0;
}
