#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool vis[3][4];
bool exist[12][12][12][12][12];  //标志这5个位置是否搜过 
int a[6];  //记录访问的5个位置 
int b[6];  //5个位置排序 
int sum;
void dfs(int m){ 
    if(m==6){
        for(int i=1;i<=5;++i){
            b[i]=a[i];
        }
        sort(b+1,b+1+5);//5个位置排序 
        if(exist[b[1]][b[2]][b[3]][b[4]][b[5]]){//看看这5个位置有没有搜过 
            return;
        }
        printf("%d %d %d %d %d\n",b[1],b[2],b[3],b[4],b[5]);
        exist[b[1]][b[2]][b[3]][b[4]][b[5]]=true;  //判断重复 
        ++sum;
        return;
    }
    int i,j;
    int i1,i2;
    int j1,j2;
    bool flag;
    for(i=0;i<3;++i){
        for(j=0;j<4;++j){
            if(vis[i][j])continue;//已经选择了 
            //如果是第一个，那么直接选 
            if(m==1){
                vis[i][j]=true;
                a[m]=i*4+j;  //记录位置 
                dfs(m+1);
                vis[i][j]=false;
                continue;
            }
            //否则，必需当上、下、左、右四个位置中至少有一个位置已选择时，才能选 
            i1=i-1;
            i2=i+1;
            j1=j-1;
            j2=j+1;
            flag=false;
            if(i1>=0){
                if(vis[i1][j]){
                    flag=true;
                }
            }
            if(i2<3){
                if(vis[i2][j]){
                    flag=true;
                }
            }
            if(j1>=0){
                if(vis[i][j1]){
                    flag=true;
                }
            }
            if(j2<4){
                if(vis[i][j2]){
                    flag=true;
                }
            }
            if(flag){//这个位置可以选了 
                vis[i][j]=true;
                a[m]=i*4+j;//记录位置 
                dfs(m+1);
                vis[i][j]=false;
            }
        }
    }
}

int main(){
    memset(vis,false,sizeof(vis));
    memset(exist,false,sizeof(exist));
    sum=0;
    dfs(1);
    printf("sum = %d\n",sum);
    return 0;
}