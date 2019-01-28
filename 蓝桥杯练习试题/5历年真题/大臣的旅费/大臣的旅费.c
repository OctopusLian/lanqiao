#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
typedef Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct node
{
int n;
int val;
Position next;
};

int count=0;
int max=0;
int x;
int *visit; //是否已遍历

Position Last(List l); //找出最后项
void Insert(int x,int q,List l,Position p); //在p后插入含x的项
void Dfs(int a,List l[]); //深度优先搜索
int Num(List l);

int main(void)
{
int n,u,v,q,a,b;
int i,j,k;
Node *head;
List *l,tmp;
Position p;

fscanf(stdin,"%d",&n);
head=(Node *)malloc(sizeof(Node)*(n+1));
l=(List *)malloc(sizeof(List)*(n+1));
visit=(int *)malloc(sizeof(int)*(n+1));

for(i=0;i<=n;i++) //初始化表头及链表
{
head[i].next=NULL;
l[i]=&head[i];
}

for(i=1;i<=n-1;i++) //建立无向图
{
fscanf(stdin,"%d%d%d",&u,&v,&q);
Insert(v,q,l[u],Last(l[u]));
Insert(u,q,l[v],Last(l[v]));
}

for(j=1;j<=n;j++)
visit[j]=0;
Dfs(1,l); //第一次遍历，找到点a，用全局变量x保存

for(j=1;j<=n;j++)
visit[j]=0;
count=0;
max=0;
Dfs(x,l); //第二次遍历，找到点b，用全局变量x保存，此时max为最大距离

printf("%d",max*10+(max+1)*max/2);

return 0;
}

Position Last(List l)
{
Position p;
for(p=l;p->next!=NULL;p=p->next);
return p;
}

void Insert(int x,int q,List l,Position p)
{
Position tmp;
tmp=(Position) malloc(sizeof(Node));

tmp->n=x;
tmp->val=q;
tmp->next=p->next;
p->next=tmp;
}

void Dfs(int a,List l[])
{
Position p;

visit[a]=1;
for(p=l[a]->next;p!=NULL;p=p->next)
if(!(visit[p->n]))
{
count+=p->val;
if(count>max)
{
max=count;
x=p->n;
}

Dfs(p->n,l);
count-=p->val;
}
}

int Num(List l)
{
int n=0;
Position p;
for(p=l->next;p!=NULL;p=p->next)
n++;
return n;
}
