#include <stdio.h>
struct mayi
{
	int direct;  //0为左，1为右 
	int dist;   //距离左端点距离 
	int cold;  //0为正常，1为感冒 	
} ;

int main()
{
int n,i,sign,j,num=0;
scanf("%d",&n);
struct mayi a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i].dist);
a[i].dist*=2;
a[i].direct=1;
a[i].cold=0;
if(a[i].dist<0) 
{
	a[i].dist*=-1;
	a[i].direct=0;	
}	
a[0].cold=1;	
} 

	
	for(;;)
   {
   	sign=0;
     	for(i=0;i<n;i++)  //所有蚂蚁走路 
   	    {
   			if(a[i].direct==0) a[i].dist--;
   			else a[i].dist++;
   	    } 
   
   	    for(i=0;i<n-1;i++)
   	   for(j=i+1;j<n;j++)
   	    {
	    if(a[i].dist==a[j].dist)
	    {
	    	if(a[i].direct==0) 
			{a[i].direct=1;	}
	    	else a[i].direct=0;
	    	
	    	if(a[j].direct==0)
			{ a[j].direct=1;}
	    	else a[j].direct=0;
	    	
	    	if(a[i].cold==1 ) a[j].cold=1; 
			
	        if(a[j].cold==1 ) a[i].cold=1; 
	    	
          }
        }
   
       for(i=0;i<n;i++)
      {
   	  if(a[i].dist>=0 && a[i].dist<=200)
   	   {
   		sign=1;
   		break;
   		
     	}
    	
       }
   
    	if(sign==0) break;
   
  }
	for(i=0;i<n;i++)
	{
		if(a[i].cold==1) num++;
	}

	printf("%d\n",num);

	return 0;
} 