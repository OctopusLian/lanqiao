#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

int m, n;
int a[210][210]={0};
int ans[44100];
int t=0;

void sr()
{
    scanf("%d %d",&m,&n);
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

}

void xx(int x1,int y1,int x,int y)
{
    int i,j;
    if(x==0||y==0)
        return;

    if(x==1)
    {
        for(i=0;i<y;i++)
        {
            ans[t]=a[x1][y1];
            y1++;

            t++;
        }

        return;

    }

    if(y==1)

    {

        for(i=0;i<x;i++)

        {

            ans[t]=a[x1][y1];

            x1++;

            t++;

        }

        return;

    }

    int v=x1,h=y1;

    ans[t]=a[x1][y1];

    t++;

    for(i=0;i<x-1;i++){v++;ans[t]=a[v][h];t++;}

    for(i=0;i<y-1;i++){h++;ans[t]=a[v][h];t++;}

    for(i=0;i<x-1;i++){v--;ans[t]=a[v][h];t++;}

    for(i=0;i<y-2;i++){h--;ans[t]=a[v][h];t++;}

    xx(v+1,h,x-2,y-2);

}

void sc()
{

    int c=n*m;

    if(c==0)return;

    printf("%d",ans[0]);

    for(int i=1;i<c;i++)printf(" %d",ans[i]);

}

int main()
{

    sr();

    int x=m,y=n;

    xx(0,0,x,y);

    sc();

    return 0;

}