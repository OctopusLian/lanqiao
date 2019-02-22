#include<iostream>
#include<stdio.h>
using namespace std;
int sum;
void SelectSort(int R[],int n){
    int i,j,k;
    int tmp;
    for(i=0;i<n-1;++i){//做第i趟排序
        k=i;
        for(j=i+1;j<n;++j){//在当前无序区R[i..n-1]中选最小的R[k]
            if(R[j]<R[k])k=j;//k记下目前找到的最小关键字所在的位置
        }
        if(k!=i){//交换R[i]和R[k]
            tmp=R[i];
            R[i]=R[k];
            R[k]=tmp;
            ++sum;
        }
    }
}

int main(){
    int N;
    int a[10005];
    int i;
    while(~scanf("%d",&N)){
        for(i=0;i<N;++i){
            scanf("%d",&a[i]);
        }
        sum=0;
        SelectSort(a,N);
        printf("%d\n",sum);
    }
    return 0;
}