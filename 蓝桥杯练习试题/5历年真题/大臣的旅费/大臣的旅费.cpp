#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct edge
{
	 int Number;
	 int Length;
	 edge* next;
	 edge(int number, int length)
	 {
		 Number = number;
		 Length = length;
		 next = NULL;
	 }
};

struct vert
{
	 int Number;
	 int PathLen;
	 bool Isvisit;
	 edge* First;
	 vert(int number)
	 {
		 Number = number;
		 Isvisit = false;
		 First = NULL;
		 PathLen = 0;
	 } 
};
void dfs(vector<vert>& GList, int num)
{
    edge*  p= GList[num].First;
    GList[num].Isvisit = true;
       for (; p!=NULL; p=p->next)
		{
			if(GList[p->Number].Isvisit == false)
			{    
				GList[p->Number].PathLen =GList[num].PathLen + p->Length;
				dfs(GList, p->Number);
			}
		}
}

int main()
{
	 vector<vert> GList;

	 int n, i, j;
	 int fir, sed, len;
	 cin>>n;
	 for (i=0; i<=n; i++)
	 {
		 GList.push_back(vert(i));
	 }
	 for(j = 1; j < n; j++)
	 {
		 edge* p1, *p2;
		 scanf("%d%d%d",&fir,&sed,&len);

		 p1 = GList[fir].First;
		 p2 = GList[sed].First;
		 //无向图
		 if (p1==NULL)
		 {
			GList[fir].First = new edge(sed, len);
		 }
		 else
		 {
			 while(p1->next!=NULL) //将边链接到顶点
			 {
				 p1 = p1->next;
			 } 
			 p1->next = new edge(sed, len);
		 }
	
		if (p2==NULL)
		 {
			GList[sed].First = new edge(fir, len);
		 }
		 else
		 {
			 while(p2->next!=NULL) //将边链接到顶点
			 {
				 p2 = p2->next;
			 } 
			 p2->next = new edge(fir, len);
		 }
	 }	
	int start, end, length = 0;

		dfs(GList, 1);
		for (j = 1; j<=n; j++)
		{
			if (GList[j].PathLen > length)//更新最长距离
			{
				start = i;
				end = j;
				length = GList[j].PathLen;
			}
			GList[j].PathLen = 0;
			GList[j].Isvisit = false;
		}
		dfs(GList, end);
		for (j = 1; j<=n; j++)
		{
			if (GList[j].PathLen > length)//更新最长距离
			{
				start = i;
				end = j;
				length = GList[j].PathLen;
			}
			GList[j].PathLen = 0;
			GList[j].Isvisit = false;
		}
	int cost = length*10;

	for (i = 1; i <= length; i++)
	{
		cost+=i;
	}

	cout<<cost<<endl;
	return 0;
}
