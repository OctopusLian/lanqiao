#include<stdio.h>
#include<string.h>
#include<queue>
int d_xy[][2]={0,-1,0,1,1,0,-1,0};
/*
* 双向广搜 康托展开
*/
int  hash[362880][2];
int factory[]={1,1,2,6,24,120,720,5040,40320};
typedef  struct 
{
	int step;
	int pos;
	char state[9];
}Node;
int toHashValue(char *map)
{
	int value=0;
	for(int i=0;i<9;i++)
	{
		int cnt=0;
        for(int j=i+1;j<9;j++)
		{
			if(map[i]>map[j])
				cnt++;
		}
        value+=cnt*factory[8-i];
	}
	return value;	
}
bool check(int x,int y)
{
	if(x<0||x>=3||y<0||y>=3)
		return true;
	return false;
}
int initStr(char *map)
{
	for(int i=0;i<strlen(map);i++)
		if(map[i]=='.')
		{
			map[i]='0';
			return i;
		}
		return 0;
}
int bfs(char *start,char *end)
{
	Node s,t;
	s.pos=initStr(start);
	strcpy(s.state,start);
	std::queue<Node>q1,q2;
	s.step=1;
	q1.push(s);
	s.pos=initStr(end);
	strcpy(s.state,end);
	q2.push(s);
	hash[ toHashValue(start)][0]=1;
	hash[ toHashValue(end)][1]=1;
	while(!q1.empty()||!q2.empty())
	{
		if(!q1.empty())
		{
			s=q1.front();
			q1.pop();
			for(int k=0;k<4;k++)
			{
				int x=s.pos/3+d_xy[k][0];
				int y=s.pos%3+d_xy[k][1];
				if(check(x,y))
					continue;
				t.pos=x*3+y;
			    strcpy(t.state,s.state);
				t.step=s.step+1;
				std::swap(t.state[t.pos],t.state[s.pos]);
				if(hash[toHashValue(t.state) ][0])
					continue;
				hash[toHashValue(t.state)][0]=t.step;
				if(hash[toHashValue(t.state)][1])
					return  hash[toHashValue(t.state)][1]+s.step-1;
				q1.push(t);
			}
		}
		if(!q2.empty())
		{
            	s=q2.front();
			q2.pop();
			for(int k=0;k<4;k++)
			{
  				int x=s.pos/3+d_xy[k][0];
				int y=s.pos%3+d_xy[k][1];
				if(check(x,y))
					continue;
				t.pos=x*3+y;
				strcpy(t.state,s.state);
				t.step=s.step+1;
				std::swap(t.state[t.pos],t.state[s.pos]);
				if(hash[toHashValue(t.state)][1])
					continue;
				hash[toHashValue(t.state)][1]=t.step;
				if(hash[toHashValue(t.state)][0])
					return  hash[toHashValue(t.state)][0]+s.step-1;
				q2.push(t);
			}
		}
		
	}
	return -1;
	
}
int  main()
{
	char start[9],end[9];
	gets(start);
	gets(end);
	printf("%d\n",bfs(start,end));
	return 0;  	
}
