#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <vector>
#include <algorithm>
#define N 100
typedef struct BiTNode//二叉树结点
{
	int data;//数据
	struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;
void CreateBalanceTree(BiTree &T,int x)//x 插入的数据 
{
	if(T == NULL)//若当前树为空
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = x;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if(x < T->data)//如果比当前结点小，插入左子树
	{
		CreateBalanceTree(T->lchild,x);
	}
	else if(x > T->data)//如果比当前结点大，插入右子树
	{
		CreateBalanceTree(T->rchild,x);
	}
}
vector<string> InOrder(BiTree T,int level,int lr)//右根左的顺序进行遍历,同时计算层次 
{ 
	int d,i,len;//
	vector<string> v,vr,vl;
	string s="";
	string pre="";
	string t="";
	char c[5];		
	sprintf(c, "%d", T->data); 
	s=c;
	len=s.length()+2;
	if(level==1) len-=2;
	if(level>1) s="|-"+s;//除了根结点外,左边都加|- 
	if(T->lchild||T->rchild) s+="-|";//如果结点有孩子 	
	for(i=0;i<len;i++)
	{
		pre+='.';	
	}
	if(T->rchild != NULL)
	{    
        vr=InOrder(T->rchild,level+1,1);
	}
	if(T->lchild != NULL)
	{
        vl=InOrder(T->lchild,level+1,-1);
	}		
	if(lr<0) 
	{
		for(i=0;i<vr.size();i++)
		{
			vr[i]="|"+pre+vr[i];
		}
		for(i=0;i<vl.size();i++)
		{
			vl[i]="."+pre+vl[i];
		}
	}
	if(lr>0) 
	{
		for(i=0;i<vr.size();i++)
		{
			vr[i]="."+pre+vr[i];
		}
		for(i=0;i<vl.size();i++)
		{
			vl[i]="|"+pre+vl[i];
		}
	}
	if(lr==0)
	{
		for(i=0;i<vr.size();i++)
		{
			vr[i]="."+pre+vr[i];
		}
		for(i=0;i<vl.size();i++)
		{
			vl[i]="."+pre+vl[i];
		}
	}
	v.insert(v.end(),vr.begin(),vr.end());//右 
	v.insert(v.end(),s);//根 
	v.insert(v.end(),vl.begin(),vl.end());//左 
	return v;
}
void print(string s)
{
	cout << s<< endl;
}
int main()
{
	int n;
	char str[500];//输入的字符串 
	char *p=NULL;//读入的每个数字 
	BiTree T = NULL;
	vector<string> v;
	gets(str);
	p= strtok(str, " ");
	while ( p != NULL ) //创建二叉树
	{
		CreateBalanceTree(T,atoi(p));
		p = strtok( NULL, " " );
	}
	v=InOrder(T,1,0);//根的层次为1 
	for_each(v.begin(), v.end(), print); 
	printf("\n");
    return 0;
}
