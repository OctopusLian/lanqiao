#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <ctime>  
using namespace std;  
#define M 100002  
  
struct boy{  
   int h;//高度  
   int count;//交换次数  
};  
boy a[M],temp[M];  
long long ans[M]={0};  
void  mergearray(int first,int mid,int last)  
{  
    int i=first,j=mid+1;  
    int m=mid,n=last;  
    int k=0,low=0;  
    while(i<=m&&j<=n)  
    {  
        if(a[i].h<=a[j].h)  
        {  
            a[i].count+=low;//后面比a[i]小的数  
            temp[k++]=a[i++];  
        }else  
        {  
            a[j].count+=mid+1-i;//前面比a[j]大的数个数  
            temp[k++]=a[j++];  
            low++;  
        }  
    }  
    while(i<=m){a[i].count+=low;temp[k++]=a[i++];}//后面比a[i]小的数  
    while(j<=n){temp[k++]=a[j++];}  
    for(i=0;i<k;i++)  
        a[first+i]=temp[i];  
}  
void mergesort(int first ,int last)  
{  
    if(first<last)  
    {  
        int mid=(first+last)>>1;  
        mergesort(first,mid);//左边有序  
        mergesort(mid+1,last);//右边有序  
        mergearray(first,mid,last);//合并序列  
    }  
}  
int main()  
{  
    int i, n;  
    long long result=0;  
    scanf("%d",&n);  
    for(i=0;i<n;i++)  
    {  
         scanf("%d",&a[i].h);  
         a[i].count=0;  
    }  
    mergesort(0,n-1);  
  /* for(i=0;i<n;i++)//显示每个人需要交换的次数 
        printf("%d ",a[i].count); 
        */  
    for(int i=1;i<n;i++)//任一个学生最多交换n-1次  
        ans[i]=ans[i-1]+i;//每个人的不高兴度=(交换次数+1)*交换次数/2,  
     //某一个小朋友最大不高兴度可能超int ，约为 5*10^9      
    for(i=0;i<n;i++)  
        result+=ans[a[i].count];  
    printf("%I64d\n",result);  
    return 0;  
}  
