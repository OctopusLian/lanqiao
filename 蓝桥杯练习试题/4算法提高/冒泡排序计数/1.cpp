#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	double r=0.1,p;
	scanf("%d",&n);
		p=pow((1+r),n);
	printf("%0.2lf",p);
	return 0;
}