#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
int a[4][4];
bool used[10];
int sum;
void display(){
    for(int i=0;i<=2;++i){
        for(int j=0;j<=3;++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int i,int j){
    if(i==2&&j==3){
        ++sum;
        if(sum<=3){
            printf("%d\n",sum);
            display();
        }
        return;
    }
    int k;
    int mi,mj;
    int mmi,mmj;
    bool flag;
    for(k=0;k<=9;++k){
        
        if(used[k])continue;  
        flag=true;
        for(mi=-1;mi<=1;++mi){
            for(mj=-1;mj<=1;++mj){
                
                mmi=i+mi;
                mmj=j+mj;
                if( 0<=mmi&&mmi<=2 && 0<=mmj&&mmj<=3 ){
                    if(a[mmi][mmj]!=-1){
                        if(abs(k-a[mmi][mmj])==1){
                            flag=false;
                            break;
                        }
                    }
                }
                
            }
            if(flag==false)break;
        }
        if(flag){
            
            a[i][j]=k;
            used[k]=true;
            
            if(j==3){
                dfs(i+1,0);
            }
            else{
                dfs(i,j+1);
            }
            
            a[i][j]=-1;
            used[k]=false;
        }
        
    }
}

int main(){  
    memset(used,false,sizeof(used));
    memset(a,-1,sizeof(a));
    sum=0;
    dfs(0,1);   
    printf("%d\n",sum);  
    return 0;
}