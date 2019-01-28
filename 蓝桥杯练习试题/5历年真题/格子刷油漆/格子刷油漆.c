#include <stdio.h>  
long long a[1001],b[1001],sum;  
#define NUM 1000000007 
int main()  
{  
    int i,n;  
    scanf("%d",&n);  
    b[1]=1;  
    for (i=2;i<=n;i++)  
        b[i]=(b[i-1]*2%NUM);  
    a[1]=1;a[2]=6;  
    for (i=3;i<=n;i++)  
        a[i]=(2*a[i-1]+b[i]+4*a[i-2])%NUM;  
    sum=4*a[n];  
    for (i=2;i<n;i++)  
        sum=((sum+8*b[n-i]*a[i-1]%NUM)%NUM+(8*a[n-i]*b[i-1])%NUM)%NUM;  
    printf("%I64d\n",sum);  
    return 0;  
}

/*
#include<cstdio>
#define MAXN 1010
#define MOD 1000000007
int main()
{
	long long DP[5][MAXN],ans=2;
	int n;
	scanf("%d",&n);
	if(n>1){
		DP[0][2]=DP[2][2]=DP[3][2]=DP[4][2]=4;
		DP[1][2]=8;
		for(int i=3;i<=n;i++){
			DP[0][i]=(DP[0][i-1]*2+DP[1][i-1]*2)%MOD;
			DP[1][i]=(DP[1][i-1]*2+DP[2][i-1]*4+DP[3][i-1]*2+DP[4][i-1]*2)%MOD;
			DP[2][i]=DP[2][i-1]*2%MOD;
			DP[3][i]=DP[1][i-1];
			DP[4][i]=DP[1][i-1];
		}
		ans=0;
		for(int i=0;i<5;i++)ans+=DP[i][n];
		ans%=MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}
*/