#include <stdio.h>
#include <windows.h>3 
int s[1000000];
// 3  13  9 
//  1 2 4 7 11 3 9 3 11 7 4 2 1    1 2 4 7 11 3 9 3 11 7 4 2 1 
int main()
{
long long n,k,t,i,j=1,g=1,z,sum=0;
scanf("%I64d%I64d%I64d",&n,&k,&t);
if(k%2==0) z=k*2;
else z=k;
s[0]=1;
do    //开始制表 
{
j+=g;
if(j>=k) j%=k; 
s[g]=j;
g++;     
}                         
while(g<=z) ; 
k=0;      
for(i=0;i<t;i++)
{
 sum+=s[k];
 k+=n;
 if(k>g-1) k-=g-1;             
}                 

                
printf("%I64d",sum);
system("pause");
 return 0;   
}
