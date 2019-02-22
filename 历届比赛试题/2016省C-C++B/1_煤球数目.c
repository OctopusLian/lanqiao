#include<stdio.h>
int main()
{
    int s=0,a=0;
    for(int i=1;i<=100;i++){
        a=a+i;
        s=s+a;
    }
    printf("%d\n",s);
}

/*
其他解决

 int a[105];
    int i,sum;
    a[1]=1;
    for(i=2;i<=100;++i)
        a[i]=a[i-1]+i;
    sum=0;
    for(i=1;i<=100;++i)
        sum=sum+a[i];
    printf("%d\n",sum);
    return 0;

*/