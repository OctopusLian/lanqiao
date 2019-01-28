#include<stdio.h>
#include<string.h>
#define MAXN 10010
#define MAXM 100010
int Du[MAXN],U[MAXM],V[MAXM];
int main()
{
    int n,i,m;
    long long ans=0;
    scanf("%d%d",&n,&m);
    memset(Du,0,sizeof(Du));
    for(i=0;i<m;i++){
        scanf("%d%d",&U[i],&V[i]);
        Du[U[i]]++;
        Du[V[i]]++;
    }
    for(i=0;i<m;i++)if(Du[U[i]]>1&&Du[V[i]]>1)ans+=(Du[U[i]]-1)*(Du[V[i]]-1)*2; 
    printf("%I64d\n",ans);
    return 0;
}

/*
#include<cstdio>
#include<cstring>
#define MAXN 10010
#define MAXM 100010
int Du[MAXN],U[MAXM],V[MAXM];
int main()
{
	int n,m;
	long long ans=0;
	scanf("%d%d",&n,&m);
	memset(Du,0,sizeof(Du));
	for(int i=0;i<m;i++){
		scanf("%d%d",&U[i],&V[i]);
		Du[U[i]]++;
		Du[V[i]]++;
	}
	for(int i=0;i<m;i++)if(Du[U[i]]>1&&Du[V[i]]>1)ans+=(Du[U[i]]-1)*(Du[V[i]]-1)*2;
	printf("%I64d\n",ans);
	return 0;
}

*/