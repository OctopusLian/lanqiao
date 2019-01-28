#include<stdio.h>
#include<iostream>
using namespace std;
const int mod=100000007;
int a,b,n,s,dp[1005][1005],i,j,jt;
void cut(int &a)
{
  while(a>=mod){
    a-=mod;
  }
  return;
}
int main(){
  scanf("%d%d%d%d",&n,&s,&a,&b);
  b%=n;
  b*=-1;
  while(b<0){
    b+=n;
  }
  a%=n;
  s%=n;
  while(s<0){
    s+=n;
  }
  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      dp[i][j]=0;
    }
  }
  dp[1][a]=dp[1][b]=1;
  for(i=1;i<n-1;++i){
    for(j=0;j<n;++j){
      jt=(j+a*(i+1))%n;
      dp[i+1][jt]+=dp[i][j];
      cut(dp[i+1][jt]);
      jt=(j+b*(i+1))%n;
      if(jt>=n){
        jt-=n;
      }
      dp[i+1][jt]+=dp[i][j];
      cut(dp[i+1][jt]);
    }
  }
  printf("%d\n",dp[n-1][s]);
  return 0;
}

/*
#define mod 100000007
int n,s,a,b,x[1001][1001],i,j,t;
fun()
{
	while(x[i+1][t]>=mod)x[i+1][t]-=mod;
}
int main()
{
	scanf("%d%d%d%d",&n,&s,&a,&b);
	b%=n;
	b*=-1;
	while(b<0)b+=n;
	a%=n;
	s%=n;
	while(s<0)s+=n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			x[i][j]=0;
	x[1][a]=x[1][b]=1;
	for(i=1;i<n-1;i++)
		for(j=0;j<n;j++)
		{
			t=(j+a*(i+1))%n;
			x[i+1][t]+=x[i][j];
			fun();
			t=(j+b*(i+1))%n;
			if(t>=n)
				t-=n;
			x[i+1][t]+=x[i][j];
			fun();
		}
	printf("%d\n",x[n-1][s]);
	return 0;
}
*/