#include<stdio.h>
 
 int main()
{
  int a,b,c,d;
  scanf("%d",&a);

  b=(int)(a/3600);
  c=(int)(a%3600)/60;
  d=(int)((a%3600)%60);
  printf("%d:%d:%d",b,c,d);
  return 0;
  
}