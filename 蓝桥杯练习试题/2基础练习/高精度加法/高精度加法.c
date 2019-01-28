#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void f(char a[],char b[])
{
	int w=200,i,j,la,lb;
	la=strlen(a);lb=strlen(b);
	char c[200];
	for(i=la;i<w;i++)a[i]=48;
	for(i=lb;i<w;i++)b[i]=48;
	a[w-1]=0;b[w-1]=0;
	for(i=0;i<la;i++)c[i]=a[i];
	for(i=0;i<w-1-la;i++)a[i]=48;j=0;
	for(i=w-1-la;i<w-1;i++){a[i]=c[j];j++;}

	for(i=0;i<lb;i++)c[i]=b[i];
	for(i=0;i<w-1-lb;i++)b[i]=48;j=0;
	for(i=w-1-lb;i<w-1;i++){b[i]=c[j];j++;}

	for(i=w;i>=0;i--)
	{
		j=a[i]+b[i]-96;
		if(j>9)a[i-1]=a[i-1]+j/10;
		c[i]=j%10+48;
	}
	c[w-1]=0;
	for(i=0;i<w;i++)if(c[i]!='0')break;
	for(;i<w-1;i++)printf("%c",c[i]);printf("\n");
}

int main()
{
	char a[200],b[200];gets(a);gets(b);
	f(a,b);
return 0;
}
