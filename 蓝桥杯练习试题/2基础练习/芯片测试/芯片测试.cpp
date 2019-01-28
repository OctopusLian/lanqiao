#include<iostream> 
#include<cstdio> 
#include<cstring> 

using namespace std; 

bool a[25][25]; 
bool v[25]; 
int n; 

bool dfs(int k) 
{ 
    if (k==n) 
    { 
        int sum=0; 
        for (int i=1;i<=n;i++) 
           if (v[i]) 
             sum++; 
         if (sum>n-sum) 
           for (int i=1;i<=n;i++) 
              if (v[i]) 
                 printf("%d ",i); 
        return true; 
    } 
     
    if (v[k]==true) 
    { 
       int len=0,s[25]; 
       for (int i=1;i<=n;i++) 
            if (!a[k][i] && v[i]) 
            { 
               s[++len]=i; 
               v[i]=false; 
            } 
       if (dfs(k+1)) return true; 
       for (int i=1;i<=len;i++) 
          v[s[i]]=true; 
    } 
     
    if (dfs(k+1)) return true; 
      
} 

int main() 
{ 
     scanf("%d",&n); 
     memset(v,true,sizeof(v)); 
     for (int i=1;i<=n;i++) 
        for (int j=1;j<=n;j++) 
        { 
            int c; 
            scanf("%d",&c); 
            if (c) a[i][j]=1; else a[i][j]=0; 
        } 
  
     dfs(1); 
     return 0; 
}