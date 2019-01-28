#include<stdio.h>
#include<string.h>
int a[500][500],b[500];

int f(int n,int m)
{
    int i,j,k,t,max=-999999;
    for(i=0;i<n;i++)
    {
        memset(b,0,m*sizeof(int));
        for(j=i;j<n;j++)
        {
            t=-999999;
            for(k=0;k<m;k++)
            {
                b[k]+=a[j][k];
                t+=b[k];
                if(t<b[k]) t=b[k];
                if(max<t) max=t;
            }
        }
    }
    return max;
}

int main()
{
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&a[i][j]);
    printf("%d",f(n,m));
}

/*
另一种解法


#include "stdio.h"
#include "string.h"
int a[500][500],b[500];
int f(int n,int m)
{int i,j,k,t,max=-999999;
for(i=0;i<n;i++)
  {memset(b,0,m*sizeof(int));
   
	for(j=i;j<n;j++)
	{t=-999999;
	for(k=0;k<m;k++)
	 {b[k]+=a[j][k];
	   t+=b[k];
	   if(t<b[k])t=b[k];
	   if(max<t)max=t;	
	 }	
	}
	
	
  }
  return max;
}
int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",&a[i][j]);
	
	
	printf("%d",f(n,m));
	
	
	
	
	return 0;
	
}
*/