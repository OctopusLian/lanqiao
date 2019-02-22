#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int MAXN=2240;
int pow_2[2240];
int main(){ 
    int N; 
    int i;
    int a,b,c,d;
    int sum;
    bool flag;
    int p,q; 
    for(i=0;i<2240;++i){
        pow_2[i]=i*i;
    }
    while(~scanf("%d",&N)){
        flag=false;
        sum=0;
        for(a=0;a<MAXN;++a){ 
            sum=pow_2[a];
            for(b=a;b<MAXN;++b){
                sum=sum+pow_2[b];
                if(sum>N){
                    sum=sum-pow_2[b];
                    continue;
                }
                for(c=b;c<MAXN;++c){
                    sum=sum+pow_2[c];
                    if(sum>N){
                        sum=sum-pow_2[c];
                        continue;
                    }
                    p=N-sum;
                    q=sqrt(p);
                    if(pow_2[q]==p){
                        printf("%d %d %d %d\n",a,b,c,q);
                        flag=true;
                        break;
                    }
                    else{
                        sum=sum-pow_2[c];
                    }
                }
                sum=sum-pow_2[b]; 
                if(flag)break;
            }
            sum=sum-pow_2[a];
            if(flag)break;
        }
    }
    return 0;
}