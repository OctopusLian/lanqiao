#include<cstdio>
#include<algorithm>
using namespace std;
const int NO=100006;
const int INF=1000000000;
struct R
{
	int a,b,w;
}r[NO*10];
int fa[NO];
int n,m,sum;
void reset_fa()
{
	for(int i=0;i<=n;i++)
		fa[i]=i;
}
bool comp(const R &a,const R &b){return a.w<b.w;}
int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
int kruskal()
{
	int i,num=0,a,b,k;
	for(i=1;i<=m;i++)
	{
		a=find(r[i].a);
		b=find(r[i].b);
		if(a!=b)
		{
			if(r[i].a==0)
			{
				num++;
				k=r[i].w;
			}
			sum+=r[i].w;
			fa[a]=b;
		}
	}
	if(num==1)
	{
		sum-=k;
	}
	return sum;
}

int main()
{
	int i=1,j,a,b;
	scanf("%d%d",&n,&m);
	reset_fa();
	while(m--)
	{
		scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].w);
		if(r[i].w<0)
		{
			sum+=r[i].w;
			a=find(r[i].a);
			b=find(r[i].b);
			if(a!=b)
				fa[a]=b;
		}
		else
			i++;
	}
	for(j=1;j<=n;j++)
	{
		scanf("%d",&a);
		if(a!=-1)
		{
			r[++i].a=0;
			r[i].b=j;
			r[i].w=a;
		}
	}
	m=i;
	sort(r+1,r+1+m,comp);
	printf("%d\n",kruskal());
	return 0;
}