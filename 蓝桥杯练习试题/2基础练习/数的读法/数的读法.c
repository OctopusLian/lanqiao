#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];int i,j,k,l;
	char b[20][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char c[20][10]={"","","shi","bai","qian","wan","shi","bai","qian","yi","shi"};
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++){
		j=a[i]-48;
		if(j==0){if(i<l-1)if(a[i+1]!=48)printf("%s ",b[j]);}
		else 
		if((l-i==2||l-i==6||l-i==10)&&j==1)printf("%s ",c[l-i]);
		else if(a[i-1]==48&&j==1)printf("%s ",c[l-i]);
		else printf("%s %s ",b[j],c[l-i]);
	}
	printf("\n");
	return 0;
}
