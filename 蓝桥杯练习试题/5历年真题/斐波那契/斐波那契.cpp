#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
LL llmul( LL a,LL b,LL mod ) {
	a%=mod;a+=mod;a%=mod;
	b%=mod;b+=mod;b%=mod;
	if ( a<b )swap( a,b );
	LL ret=0;
	while ( b ) {
		if ( b&1 )ret=( ret+a )%mod;
		a=( a<<1 )%mod;
		b/=2;
	}
	return ret;
}

struct matrix {
	LL x[3][3];
	matrix() {memset( x,0,sizeof x );}
};
matrix mmul( matrix &A,matrix &B,LL mod ) {
	matrix ret;
	for ( int i=1; i<=2; i++ )
		for ( int j=1; j<=2; j++ )
			for ( int k=1; k<=2; k++ )
				ret.x[i][j]=( ret.x[i][j]+llmul( A.x[i][k],B.x[k][j],mod ) )%mod;
	return ret;
}
matrix E;
matrix A;
LL fib( LL n,LL mod ) {
	matrix O=E,B=A;
	while ( n ) {
		if ( n&1 )O=mmul( O,B,mod );
		B=mmul( B,B,mod );
		n/=2;
	}
	return O.x[1][2];
}
//[(2*3)%5]%3=1
//(2%3)*(3%3)=0
LL solve( LL n,LL m,LL mod ) {
	//f(n)%f(m)%mod
	LL t=n/m;
	//(f(m-1)^t*f(n%m))%f(m)%mod;
	//f(i)^2%f(i-1)=(-1)^(i+1)
	LL p=t/2,q=t%2;
	//{f(m-1)^q*(-1)^(pm)*f(n%m)}%f(m)%mod
	LL fuhao=p*m%2==0?1:-1;
	if ( q==0 ) {
		LL ans=fib( n%m,mod )*fuhao;
		ans%=mod;
		ans+=mod;
		return ans%mod;
	}
	if ( n%m==0 )return 0;
	//f(m-1)*f(n%m)*fuhao%f(m)%mod
//	cout<<fib(m-1,mod<<5)*fib(n%m,mod*111111)*fuhao%fib(m,mod<<5)%mod<<endl;
//	cout<<fib(m-1,mod<<5)<<"*"<<fib(n%m,mod<<5)<<"*"<<fuhao<<"%"<<fib(m,mod<<5)<<"%"<<mod<<endl;
//	cout<<fib(n%m,mod<<5)*fib(m-1,mod<<5)/fib(m,mod<<5)<<endl;
	//x%y%mod=(x-a*y)%mod
	//a=[x/y]
	LL x=(llmul(fib(n%m,mod),fib(m-1,mod),mod)*fuhao%mod+mod)%mod;
	LL y=fib(m,mod);
	LL a=fib(n%m-1,mod);
	if(n%m%2==0)a--;
	if(fuhao<0)a++;
	a=(a%mod+mod)%mod;
//	cout<<a<<endl;
	return ((x-llmul(a,y,mod))%mod+mod)%mod;
}

int main() {
	int i,j;
	A.x[1][2]=A.x[2][1]=A.x[2][2]=1;
	E.x[1][1]=E.x[2][2]=1;
	LL n,m,mod;
	while ( cin>>n>>m>>mod )
		cout<<( solve( n+2,m,mod )-1+mod )%mod<<endl;
	return 0;
}
