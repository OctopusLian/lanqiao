#include<stdio.h>
#include<malloc.h>
int a[100001],b[100001],c[100001],d[10001];
struct tubiao
{
    int n;
    struct tubiao *next;
}tu[10001];

void add(int u,int v)
{
    struct tubiao *p=(struct tubiao*) malloc(sizeof(struct tubiao));
    p->n=v;
    p->next=NULL;
    struct tubiao *q=&tu[u];
    while(q->next)
       {  q=q->next;
          
       }
    q->next=p;
}

void paixu(int first,int last)
{  
    if(first<last)
     {
          int i=first,j=last,ka=a[first],kb=b[first],kc=c[first];
          while(i<j)
          {
              while(i<j&&kc<=c[j])
                  j--;
              a[i]=a[j];b[i]=b[j];c[i]=c[j];
              while(i<j&&kc>=c[i])
                  i++;
             a[j]=a[i];b[j]=b[i];c[j]=c[i];
             
         }
         a[i]=ka;b[i]=kb;c[i]=kc;
         paixu(first,i-1);
         paixu(i+1,last);
     }
    
}

int f1(int i)
{
	if(d[i]==i)
	  return i;
    int u=f1(d[i]);
    d[i]=u;
	return d[i];
}

int main()
{
    int n,m,i1,u,v,t,i2;
    scanf("%d%d",&n,&m);
    for(i1=0;i1<m;i1++)
    {   scanf("%d%d%d",&u,&v,&t);
        a[i1]=u;b[i1]=v;c[i1]=t;
        add(u,v);
        add(v,u);
    }
    paixu(0,m-1);
    int  total=0,tianshu=0;
 for(i1=1;i1<=n;i1++)
    d[i1]=i1;
 for(i1=m-1;i1>=0;i1--)
 {     int ko=f1(a[i1]);
       int ok=f1(b[i1]);
 	 if(ko==ok)
 	     {
     	    continue;	
     	 }
 	 else 
 	    {
    	 	d[ko]=b[i1];
    	 	if(tianshu!=c[i1])
    	 	   {
   	 	    	 total++;
   	 	    	 tianshu=c[i1];
   	 	       }
   	 	    
    	 }
 }
  printf("%d\n",total);
    return 0;
}