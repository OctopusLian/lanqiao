#include<iostream>
#include<stdio.h>
using namespace std;
int a[10005];//a[i]表示位置i的瓶子编号
int b[10005];//b[i]表示i号瓶子的位置。没有这个数组的话，需要在a数组中循环找到i号瓶子（O(n)），用这个数组的话是O(1)
int main(){
    int N;
    int i;
    int id;
    int sum;
    //设瓶子1为位置i的瓶子，瓶子2为i号瓶子 
    int id1,id2;  //瓶子1的编号，瓶子2的编号 
    int pos1,pos2;//瓶子1的位置，瓶子2的位置 
    while(~scanf("%d",&N)){ 
        for(i=1;i<=N;++i){
            scanf("%d",&id);
            a[i]=id;//位置i放id号瓶子 
            b[id]=i;//id号瓶子放到位置i 
        }
        sum=0;
        for(i=1;i<=N;++i){//位置从1遍历到N 
            if(a[i]==i)continue;//位置i放的是i号瓶子
            //否则，瓶子2与瓶子1交换 
            id1=a[i];
            pos1=i;
            id2=i;
            pos2=b[i];//没有b数组的话，需要在a数组中找到i号瓶子 
            ++sum;
            //瓶子1放到瓶子2的位置 
            a[pos2]=id1;//瓶子2的位置（pos2）放瓶子1（id1） 
            b[id1]=pos2;//瓶子1（id1）放到瓶子2的位置（pos2） 
            //瓶子2放到瓶子1的位置 
            a[pos1]=id2;//瓶子1的位置放瓶子2 
            b[id2]=pos1;//瓶子2放到瓶子1的位置 
        }
        printf("%d\n",sum);
    }
    return 0;
}