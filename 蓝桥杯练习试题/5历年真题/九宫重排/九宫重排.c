#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Node
{
    char tab[3][3];
    int x,y;
    int no;
}Node,*pNode;
int vx[4]={-1,1,0,0};
int vy[4]={0,0,-1,1};
Node res[400000];
int front=0,rear=0;
int vis[4000000],fact[9]; 

void input(pNode start);
void bfs(pNode start,pNode end);
void init_lookup_table();
int try_to_insert(int s);
int main()
{
    Node start,end;
    input(&start);
    input(&end);
    bfs(&start,&end);
    printf("-1\n");
    return 0; 
}
void input(pNode start)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%c",&( (start->tab)[i][j] ));
            if((start->tab)[i][j]=='.')
            {
                start->x = i;
                start->y = j;
            }
        }
    }
    start->no = 0;
    getchar();
}
void bfs(pNode start,pNode end)
{
    int i,j;
    char ch;
    pNode tmp;
    init_lookup_table();
	memcpy(&res[rear],start,sizeof(res[rear]));
	try_to_insert(rear); 
	rear++;
    while(front!=rear)
    {
        //printf("%d  ",rear);
        tmp = &res[front];
        if(memcmp(tmp->tab,end->tab,sizeof(end->tab))==0)
        {
            printf("%d\n",tmp->no);
            exit(0);
        }
        int no = tmp->no;
        for(i=0;i<4;i++)
        {
            int xx = tmp->x+vx[i];
            int yy = tmp->y+vy[i];
            if(xx>=0 && xx<3 && yy>=0 && yy<3)
            {
            	pNode p = &res[rear];
            	memcpy(p,tmp,sizeof(res[front]));
            	p->tab[tmp->x][tmp->y] = p->tab[xx][yy];
            	p->tab[xx][yy] = tmp->tab[tmp->x][tmp->y];
            	p->no = no+1;
            	p->x = xx;
            	p->y = yy;
                if(try_to_insert(rear))
                {
                    rear++;
                }
            }
        }
        front++;
        //printf("%d  ",rear);
    }
}

void init_lookup_table()
{
	int i;
	fact[0] = 1;
	for(i=1;i<9;i++)
	{
		fact[i] = fact[i-1]*i;
	}
}

int try_to_insert(int s)
{
	int i,j;
	int code = 0;
	for(i=0;i<9;i++)
	{
		int cnt = 0;
		for(j=i+1;j<9;j++)
		{
			if(res[s].tab[j/3][j%3] < res[s].tab[i/3][i%3])
			{
				cnt++;
			}
			code += fact[8-i]*cnt;
		}
	}
	if(vis[code])
	{
		return 0;
	}
	return vis[code] = 1;
}