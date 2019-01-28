#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int a[15][15];
int m,n;
int mx,sum;
int mi[][2]={{0,1},{0,-1},{1,0},{-1,0}};

struct ki{
    int x,y;
    int sum;
    int tep;
};

void dfs(int x,int y,int s,int tep){
    if(s>sum/(2.0))
        return ;
    else if(s==sum/(2.0)){
        if(tep<mx)
            mx=tep;
   //     printf("s=%d\n",s);
    }
    else{
        for(int i=0;i<4;i++){
            int tx=x+mi[i][0];
            int ty=y+mi[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m)
                continue;
            if(a[tx][ty]!=-1){
                int tem=a[tx][ty];
                a[tx][ty]=-1;
            //    printf("tx=%d ty=%d s=%d tep=%d\n",tx,ty,s,tep);
                dfs(tx,ty,s+tem,tep+1);
                a[tx][ty]=tem;
            }
        }
    }
}

int main(){
    while(cin>>m>>n){
        sum=0;
        for(int i=0;i<n;i++)
            for(int k=0;k<m;k++){
                scanf("%d",&a[i][k]);
                sum+=a[i][k];
            }
        mx=10000;
        int tem=a[0][0];
        a[0][0]=-1;
        dfs(0,0,tem,1);
        printf("%d\n",mx==10000?0:mx);
    }
    return 0;
}
