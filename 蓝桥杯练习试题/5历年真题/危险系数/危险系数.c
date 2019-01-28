#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *pNext;
};
struct Node tab[1001];
int visit[1001]={0};
int way[1001]={0};
int count[1001]={0};
int cnt=0;
void Insert(int n,int x);
void Init(int n);
void dfs(int x,int y,int n);
int fun(int n);
int main()
{
	int x,y,n,m,u,v;
	scanf("%d%d",&n,&m);
	Init(n);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		Insert(u,v);
		Insert(v,u);
	}
	scanf("%d%d",&x,&y);
	dfs(x,y,0);
	int ret=fun(n);
	printf("%d\n",ret);
	return 0;
}
int fun(int n)
{
	int i;
	int ret=0;
	for(i=1;i<=n;i++)
	{
		if(count[i]==cnt)
		{
			ret++;
		}
	}
	return (ret-2);
}
void dfs(int x,int y,int n)
{
	visit[x]=1;
	way[n]=x;
	struct Node *p=&tab[x];
	if(x==y)
	{
		int i;
		cnt++;
		for(i=0;i<=n;i++)
		{
			count[way[i]]++;
		}
		return ;
	}
	while((p=p->pNext)!=NULL)
	{
		if(visit[p->data]!=1)
		{
			dfs(p->data,y,n+1);
			visit[p->data]=0;
		}
	}
}
void Init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		tab[i].data=i;
		tab[i].pNext=NULL;
	}
}

void Insert(int n,int x)
{
	struct Node *p=&tab[n];
	while(p->pNext!=NULL)
	{
		p=p->pNext;
	}
	struct Node *new=(struct Node *)malloc(sizeof(struct Node));
	p->pNext=new;
	new->data=x;
	new->pNext=NULL;
}
