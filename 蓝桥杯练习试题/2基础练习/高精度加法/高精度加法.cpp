#include<cstdio>
 #include<iostream>
 #include<cstring>
 using namespace std;
 int a[401],alen,b[401],blen,c[400],clen;
 char st[400];
 int main()
 {
 int i,j,n,len;
 scanf("%s",st);
 alen= strlen(st);
 for(i=1;i<=alen;i++)
 a[i]= st[alen-i]-48;
 scanf("%s",st);
 blen= strlen(st);
 for(i=1;i<=blen;i++)
 b[i]= st[blen-i]-48;
 if(alen>blen) clen=alen;
 else clen=blen;
 for(i=1;i<=clen;i++)
 c[i]=a[i]+b[i];
 for(i=1;i<=clen;i++)
 {
 if(c[i]>=10)
 {
 c[i+1]=c[i+1]+ c[i]/10;
 c[i]=c[i]%10;
 }
 }
 if(c[clen+1]>0)clen++;
 for(i=clen;i>=1;i--)
 {
 printf("%d",c[i]);
 }
 printf("\n");
 return 0;
 } 