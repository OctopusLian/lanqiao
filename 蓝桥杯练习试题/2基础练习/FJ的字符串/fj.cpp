#include<iostream>
#include<cstdio>
using namespace std;

void dfs(int k,int p)
{
	if (k==1)
	{
	   printf("%c",p+'A');
	   return;	

	}
	dfs(k/2,p-1);dfs(1,p);dfs(k/2,p-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    int sum=1;
    n--;
    for (int i=1;i<=n;i++) sum=sum*2+1;
	    dfs(sum,n);	

	return 0;

}