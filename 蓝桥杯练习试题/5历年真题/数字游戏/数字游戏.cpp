#include <stdio.h>  
int a[1000000];  
int main()  
{  
    __int64 i,m,n,k,t,s,j;  
    __int64 sum=0;  
    scanf("%I64d%I64d%I64d",&m,&k,&n);      
    a[1] = 1; 
    for(i=2;i<m*n;i++)  
    {  
        a[i] = a[i-1];  
        a[i] = a[i] + i-1;  
      
        if( a[i] >= k )  
                  a[i] = a[i]%k; 
		if(a[i]==1)
		{
			for(j=1;j<=i;j++)
			{
				if(a[j]!=a[i-j+1])
					break;
			}
			if(j==i+1)
			{
		    	t=i;
		     	break;
			}
		}
    }  
//	printf("t=%d\n",t);
        /*for(i=1;i<=t;i++)  
    {  
         printf("%d ",a[i]);
    }  
		puts("");*/
		a[0]=a[t];
    for(i=1;i<n*m;i+=m)  
    {  
       
              sum += a[i%t];  
			 // printf("%d ",a[i%t]);
    }  
    printf("%I64d\n",sum);  
      
    return 0;  
}