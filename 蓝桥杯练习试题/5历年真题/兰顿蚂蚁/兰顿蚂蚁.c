#include<stdio.h>

int a[1000][1000]={
	0
};

char f(int i,char now)
{
	if(i==0&&now=='U'||i==1&&now=='D')
	  return 'R';
    else if(i==0&&now=='R'||i==1&&now=='L')
      return 'D';
    else if(i==0&&now=='D'||i==1&&now=='U')
      return 'L';
    else if(i==0&&now=='L'||i==1&&now=='R')
       return 'U';
	
}

int main()
{
	int n,m,i1,i2,x,y,k;
	char s;
	scanf("%d%d",&n,&m);
	for(i1=0;i1<n;i1++)
	   for(i2=0;i2<m;i2++)
	       scanf("%d",&a[i1][i2]);
    scanf("%d%d",&x,&y);
	getchar();
	scanf("%c%d",&s,&k);
	char now=s;
	while(k--)
	{  if(a[x][y]==0)
	       a[x][y]=1;
       else 
          a[x][y]=0;
       
	   now=f(a[x][y],now);
	   if(now=='U')
	       x--;
	    else if(now=='D')
		    x++;
	   else if(now=='L')
	       y--;
	   else
	       y++;
	    	
	}  
	printf("%d %d\n",x,y);
	return 0;
}