#pragma comment(linker,"/STACK:102400000,102400000")
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>

#define sf scanf
#define pf printf
#define fst first
#define scd second
#define pb push_back
#define mkp make_pair
#define cls(a,x) memset(a,x,sizeof a)
#define dt(x) cout<<#x<<"="<<x<<" ";
#define dte(x) cout<<#x<<"="<<x<<endl;

#if(defined(_WIN32)||defined(__WIN32__))
typedef __int64 LL;
typedef unsigned __int64 ULL;
#define ll I64
#else
typedef long long LL;
typedef unsigned long long ULL;
#define I64 ll
#endif

using namespace std;
template<class T>inline void scaf(T &v)
{
	char ch;
	while(ch=getchar())
		if(ch<='9' && ch>='0') break;
	v=ch-'0';
	while(ch=getchar())
		if(ch<='9' && ch>='0') v=(v<<1)+(v<<3)+ch-'0';
		else break;
}

typedef pair<int,int > PII;
const int MX=50100;
const int mod=1000000007;

int sp[51][51];
int g[51][51];
LL dp[51][51][13];

inline void run()
{
	int n,m,k,i,j,ii,jj,kk;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=50;++i)
		sp[i][1]=sp[1][i]=1;
	for(i=2;i<=n;++i)
		for(j=2;j<=m;++j)
			sp[i][j]=sp[i-1][j]+sp[i][j-1];
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			scanf("%d",&g[i][j]);
			dp[i][j][1]=sp[i][j];
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			for(ii=1;ii<=i;++ii)
			{
				for(jj=1;jj<=j;++jj)
				{
					if(g[ii][jj]<g[i][j])
					{
						for(kk=2;kk<=k;++kk)
						{
							dp[i][j][kk]+=dp[ii][jj][kk-1]*sp[i-ii+1][j-jj+1];
							dp[i][j][kk]%=mod;
						}
					}
				}
			}
		}
	}
//	for(i=1;i<=n;++i)
//	{
//		for(j=1;j<=m;++j)
//		{
//			pf("%d ",dp[i][j][k]);
//		}
//		putchar(10);
//	}
	LL Ans=0;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			Ans+=dp[i][j][k]*sp[n-i+1][m-j+1];
			Ans%=mod;
		}
	}
	pf("%I64d\n",Ans);
}

int main()
{
	run();
	return 0;
}
