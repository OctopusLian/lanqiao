#include<stdio.h>
int check(int t1,int t2,int t3) 
{
	 int result;
	 int temp1=45;
	 long temp2=362880;
	 long a1=t1%10+t1/10%10+t1/100%10;
	 long b1=t2%10+t2/10%10+t2/100%10;
	 long c1=t3%10+t3/10%10+t3/100%10;
	 long a2=(t1%10)*(t1/10%10)*(t1/100%10);
	 long b2=(t2%10)*(t2/10%10)*(t2/100%10);
	 long c2=(t3%10)*(t3/10%10)*(t3/100%10);
	 if(((a1+b1+c1)==temp1) && (a2*b2*c2==temp2))
	    result=1;
	 else
	    result=0;
	 return result;	

 
}
int main()
{
	int x;
	for(x=123;x<333;x++)  
	if(check(x,2*x,3*x)) 
 		printf("%d %d %d\n",x,2*x,3*x); 
}
