#include<stdio.h>
int main()
{
	int v1,v2,t,s,l,s1=0,s2=0,i=0;
	scanf("%d %d %d %d %d",&v1,&v2,&t,&s,&l);
	while(s1<l&&s2<l)
	{
		s1+=v1;
		s2+=v2;
		i++;
		if(s1==l||s2==l)break;
		if(s1-s2>=t)s1-=v1*s;
	}
	if(s1>s2)      printf("R\n");
	else if(s2>s1) printf("T\n");
	else		   printf("D\n");
	printf("%d",i);
    return 0;
}