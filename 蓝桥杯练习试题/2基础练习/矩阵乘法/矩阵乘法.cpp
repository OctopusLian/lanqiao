#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[101][101];
int c[101][101];
int ans[101][101];
int main()
{
     int i,j,k,l,m,n;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
     memset(ans,0,sizeof(ans));
     for(i=1;i<=n;i++) ans[i][i]=1;
     for(k=1;k<=m;k++)
     {    memset(c,0,sizeof(c));
         for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(l=1;l<=n;l++)c[i][j]+=ans[i][l]*a[l][j];
         for(i=1;i<=n;i++)for(j=1;j<=n;j++)ans[i][j]=c[i][j];
     }
     for(i=1;i<=n;i++)
     {
         for(j=1;j<n;j++)printf("%d ",ans[i][j]);
         printf("%d\n",ans[i][n]);
     }
     return 0;
 }