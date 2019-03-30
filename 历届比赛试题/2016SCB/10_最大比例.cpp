#include <stdio.h>  
#include <algorithm>  
#include <queue>  
using namespace std;  
#define LL long long  
struct fs  
{  
    LL up,down;  
};  
int n;  
LL arr[110];  
fs Fs[110];  
  
bool cmp(LL a,LL b)  
{  
    return a > b;  
}  
  
LL Gcd(LL a,LL b)  
{  
    if( b == 0 )return a;  
    return Gcd(b,a%b);  
}  
LL Get(LL a, LL b)  
{  
    if( a < b) a ^= b ^= a ^= b;  
    LL v[30];  
    queue<LL>team;  
    if( a == b || a / b == a) return b;  
    v[0] = a, v[1] = b;  
    v[2] = a / b;  
    int top = 3,i,j;  
    team.push(a/b);  
    while(team.size())  
    {  
        LL now = team.front();  
        team.pop();  
        for(i = 0 ; i < top ; i ++)  
        {  
            LL temp = (v[i] > now) ? v[i] / now : now / v[i];  
            bool find = false;  
            for(j = 0 ; j < top ; j ++)  
                if( v[j] == temp) find = true;  
            if(find == true) continue;  
            team.push(temp);  
            v[top++] = temp;  
        }  
    }  
    LL ans = v[0];  
    for(i = 0 ; i < top ; i ++)   
        if(v[i] != 1)   
        {  
            ans = v[i];  
            break;  
        }  
    for(i = 0 ; i < top ; i ++)  
        if( v[i] < ans && v[i] != 1) ans = v[i];  
    return ans;  
}  
int main()  
{  
    int i,j;  
    scanf("%d",&n);  
    for(i = 0 ; i < n ; i ++) scanf("%lld",&arr[i]);  
    sort(arr,arr+n,cmp);  
    int top = 1;  
    for(i = 1; i < n ; i ++)  
        if(arr[i] != arr[i-1]) arr[top++] = arr[i];  
    n = top;  
    for(i = 0 ; i < n - 1; i ++)  
    {  
        LL gcd = Gcd(arr[i],arr[i+1]);  
        Fs[i].up = arr[i] / gcd;  
        Fs[i].down = arr[i+1] / gcd;  
    }  
    LL x = Fs[0].up;  
    for(i = 0 ; i < n - 1 ; i ++)  
        x = Get(x,Fs[i].up);  
    LL y = Fs[0].down;  
    for(i = 0 ; i < n - 1; i ++)  
        y = Get(y,Fs[i].down);  
    printf("%lld/%lld\n",x,y);  
    return 0;  
}  