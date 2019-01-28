#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TNode
{
	int key;
	struct TNode *left;
	struct TNode *right;
}TNode, *Tree;

Tree insert(Tree root, Tree src)
{
	if(root == NULL)
	{
		root = src;
	}
	else if(src->key > root->key)
	{
		root->left = insert(root->left, src);
	}
	else
	{
		root->right = insert(root->right, src);
	}
	return root;
}

char l[1000];

#define U 1
#define D 2
#define S ('.')

void print(Tree root, int s, int dir)
{
	if(root != NULL)
	{
		int i;
		char buf[10];
		sprintf(buf, "|-%d-", root->key);
		int len = strlen(buf);
		for(i = 0; i < len; i++)
		{
			l[s + i] = S;
		}
		if(dir == D)
		{
			l[s] = '|';
		}
		print(root->left, s + len, U);
		
		l[s] = '\0';
		if(root->left == NULL && root->right == NULL)
		{
			buf[len - 1] = '\0';
			printf("%s%s\n", l, buf);
		}
		else
		{
			printf("%s%s|\n", l, buf);
		}
		l[s] = S;
		
		if(dir == U)
		{
			l[s] = '|';
		}
		print(root->right, s + len, D);
		l[s] = S;
	}
}

void printPre(Tree root, int s)
{
	if(root != NULL)
	{
		int i;
		char buf[10];
		sprintf(buf, "%d-", root->key);
		int len = strlen(buf);
		for(i = 0; i < len; i++)
		{
			l[s + i] = S;
		}
		print(root->left, s + len, U);
		
		printf("%s|\n", buf);
		
		print(root->right, s + len, D);
	}
}

int main(void)
{
	int n;
	Tree tree = NULL;
	while(scanf("%d", &n) > 0)
	{
		Tree neo = malloc(sizeof(TNode));
		neo->key = n;
		neo->left = neo->right = NULL;
		tree = insert(tree, neo);
	}
	printPre(tree, 0);
	return 0;
}
