#include<stdio.h>
int main()
{
	int i,j;
	printf("Nine-by-nine Multiplication Table\n");
	printf("--------------------------------------\n");
	for(i=1;i<=9;i++)
		printf("%d ",i);
	printf("\n");
	printf("--------------------------------------\n");
	for(i=1;i<=9;i++)
	{
		printf("%d ",i);
		for(j=1;j<=i;j++)
			printf("%d ",i*j);
		printf("\n");
	}
	printf("--------------------------------------\n");
	return 0;
}
