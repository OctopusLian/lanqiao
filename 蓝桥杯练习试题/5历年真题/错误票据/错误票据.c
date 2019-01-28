#include <stdio.h>    
int main()  
{  
    int a[10001]={0};
    long m,min=100000,max=0,i,n;
	char c;
	scanf("%d",&n);
		for(i=0;i<n;i++)
			while(1)
			{
			scanf("%ld",&m);
			if(m>max) max=m;
			if(m<min) min=m;
			a[m]++;
			c=getchar();
			if(c!=' ') break;
			}

	for(i=min;i<=max;i++)
	{
	 if(a[i]==0) printf("%ld ",i);
	 if(a[i]==2) m=i;
	}
	  printf("%ld",m);
	
	return 0;
}  
