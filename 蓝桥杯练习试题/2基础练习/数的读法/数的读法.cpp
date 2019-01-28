#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<cstdlib>

 using namespace std;
 char df[][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
 char s[15];
 int main()
 {
 scanf("%s",s);
 int lens=strlen(s);
 bool bk=false;
 for (int i=0;i<lens;i++)
 {
 int p,lendf;
 p=s[i]-'0';
 if (p!=0)
 {
 bk=false;
 lendf=strlen(df[p]);

 if (s[i-1]-'0'==0) 
 printf("ling ");

 if ((lens-i)%4==2 && p==1 /*&& s[i-1]-'0'==0 && s[i-2]-'0'==0*/ && i==0)
 {
 printf("shi ");
 continue;
 }

 for (int j=0;j<lendf;j++)
 printf("%c",df[p][j]);
 printf(" ");

 if ((lens-i)%4==2) printf("shi ");
 if ((lens-i)%4==3) printf("bai ");
 if ((lens-i)%4==0) printf("qian ");
 }
 if ((lens-i)%4==1)
 {
 if ((lens-i)/4==2)
 {
 bk=true;
 printf("yi ");
 }
 if (bk==false && (lens-i)/4==1) printf("wan ");
 }

 }
 return 0;
 } 
 