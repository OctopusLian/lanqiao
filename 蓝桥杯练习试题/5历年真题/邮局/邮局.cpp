#include<iostream>  //邮局 
#include<stdlib.h>
#include<math.h>
using namespace std;
int n,m,k,j,c[55][2],y[27][2],d[12],f1,f2,f[55]={0};
float yc[27][55],s=1000000000;
int dfs(int t,int i,int o[12],float w[55],float sum)
{
    if(i<=m+1)
    {
        if(t==k)
        {
             if(sum<s)
            {
                s=sum;
                for(j=0;j<k;j++)
                    d[j]=o[j];
            }
        }
        else if(i<=m&&t<k)
        {
            float ww[55];
            for( j=1;j<=n;j++)
            ww[j]=w[j];
            dfs(t,i+1,o,w,sum);f1=1,f2=0;
            if(!f[i])
            {
                o[t]=i;
            if(t>0)
            {
                f2=1;
                 for( j=1;j<=n;j++)
                {
                    if(ww[j]>yc[i][j])
                    {
                        sum=sum-ww[j]+yc[i][j];
                        ww[j]=yc[i][j];
                        f1=0;
                    }
                }
            }
            else
             {
                for( j=1;j<=n;j++)
                {
                    sum+=yc[i][j];
                    ww[j]=w[j]=yc[i][j];
                }
            }
            if(f1&&f2)
            {
                f[i]=1;
                dfs(t,i+1,o,w,sum);
            }
            else
            dfs(t+1,i+1,o,ww,sum);
            }
        }
    }
}

int main()
{
    int i,j,o[12];
    float w[55],ww[55];
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
    cin>>c[i][0]>>c[i][1];
    for(i=1;i<=m;i++)
    {
    cin>>y[i][0]>>y[i][1];
    for(j=1;j<=n;j++)
    yc[i][j]=sqrt((c[j][0]-y[i][0])*(c[j][0]-y[i][0])+(c[j][1]-y[i][1])*(c[j][1]-y[i][1]));
    }
    dfs(0,1,o,w,0);
    for(i=0;i<k;i++)
    cout<<d[i]<<" ";
}