#include<stdio.h>
int main()
{
    int a,b,c,d,i;
    for(i=1000;i<=9999;i++){  
        a=i/1000;
        b=i/100%10;
        c=i/10%10;
        d=i%10;
        if(a==d&&b==c)
            printf("%d\n",i);
    }
    
    return 0;
}