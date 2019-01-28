#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

char A[15],B[15];

int main()
{
    scanf("%s",A);
    scanf("%s",B);
    int a=strlen(A);
    int b=strlen(B);
    int count=0;
    if(a!=b) //长度不等
    {
        printf("1\n");
        return 0;
    }
    //长度相等

    else
    {
        for(int i=0;i<a;i++)
        {
            if((A[i]!=B[i]))
            {
                if(abs(A[i]-B[i])!=32)
                {
                    printf("4\n");
                    return 0;
                }
                else 
                {
                    ++count;
                    continue;
                }
            }
        }
        if((count==0))
            printf("2\n");
        else
            printf("3\n");
    }
    return 0;
}