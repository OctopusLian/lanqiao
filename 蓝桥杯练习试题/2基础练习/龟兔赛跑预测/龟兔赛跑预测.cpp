#include<cstdio>
 #include<iostream>
 using namespace std;
 int main()
 {
     int v1,v2,t,s,L,L1=0,L2=0,ans=0,i,j;
     bool bk=true;
     scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&L);
     while(1)
     {
         if(L1-L2>=t&&L1<L&&L2<L)
         {
            for(i=1;i<=s;i++)
            {
               if(L1<L&&L2<L)
               {
              L2+=v2;
              ans++;
               }
            }
         }
         else
         {
             L2+=v2;
             L1+=v1;
             ans++;
         }
         if(L1>=L) break;
         if(L2>=L) break;
     }
     if(L1>=L&&L2>=L){printf("D\n%d\n",ans);return 0;}
     if(L1>=L) {printf("R\n%d\n",ans); return 0;}
     if(L2>=L) {printf("T\n%d\n",ans); return 0;}
     return 0;
 }