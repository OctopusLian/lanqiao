#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int a[100005];

int main(){
    int n;
    while(cin>>n){
        char c[1005];
        int b[105],t=0;
        memset(a,0,sizeof(a));
        getchar();
        while(n--){
            gets(c);
            int tc=strlen(c);
            c[tc]=' ',c[tc+1]=0;
            int tem=0;
            for(int i=0;i<=tc;i++){
                if(c[i]!=' '){
                    tem=tem*10+c[i]-'0';
                }
                else{
                    a[tem]++;
                    b[t++]=tem;
                    tem=0;
                }
            }
        }
        int dh,ch;
        sort(b,b+t);
        for(int i=b[0];i<b[t-1];i++)
            if(a[i]==0)
                dh=i;
            else if(a[i]==2)
                ch=i;
        cout<<dh<<' '<<ch<<endl;
    }
    return 0;
}
