#include<stdio.h>
int main()
{
    int s[50005],a,i,min,max,count=0,j;
    scanf("%d",&a);
    for( i = 0; i < a; i++) {
        scanf("%d",&s[i]);
    }
    for( i = 0; i <a;i++ ){ 
		min=s[i];
		max=s[i];
        for( j = i; j <a; j++) {
			if(min>s[j]){min =s[j];}
			if(max<s[j]){max =s[j];}
			if((max-min)==(j-i)){
				count++;
			}

        }
    }
	printf("%d",count);
    return 0;
}