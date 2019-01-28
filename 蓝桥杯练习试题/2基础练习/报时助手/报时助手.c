#include<stdio.h>
#include<string.h>
int main()
{
	int h,m;
	char g[50][50]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	char s[10][10]={"twenty","thirty","forty","fifty"};
	scanf("%d%d",&h,&m);
	if(m==0)if(h<21)printf("%s o'clock",g[h]);else {printf("%s %s o'clock",s[h/10-2],g[h%10]);}
	else {
		if(h<21)printf("%s ",g[h]);else {printf("%s %s ",s[h/10-2],g[h%10]);}
		if(m<21)printf("%s ",g[m]);else {printf("%s %s ",s[m/10-2],g[m%10]);}
		}
	printf("\n");
return 0;
}