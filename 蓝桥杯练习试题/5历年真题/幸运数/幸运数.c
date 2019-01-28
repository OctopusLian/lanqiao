#include<stdio.h>
#define MAXN 1000010
int flag[MAXN];
int m,n,a[MAXN],s[MAXN],size=0;

int fa(int k)
{
	if(flag[k])
		return a[k];
	return fa(k-1);
}

int main()
{
	int i, p, k, j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i+=2)
	{
		s[++size]=i; 
		flag[i]=1; 
		a[i]=size;
	}
	for(i=2;i<=size;i++)
	{
		int Mod=s[i],d=s[i]-1;
		if(Mod>size)
			break;
		for(p=1,j=Mod;j<=size;j+=Mod,p++)
		{
			flag[s[j]]=0;
			for(k=1;k<Mod&&k+j<=size;k++)
			{
				s[++d]=s[j+k];
				a[s[j+k]]-=p;
			}
		}
		size=d;
	}
	printf("%d\n",fa(n-1)-fa(m));
	return 0;
}