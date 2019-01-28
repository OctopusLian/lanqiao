#include<stdio.h>  
int changes(char s[],char x,int n); 
char x='0'; 
int main(void) 
{ 
   int n,i,k=0,b[26]={0},j; 
   char y,s[8000]={0}; 
   scanf("%d",&n); 
   getchar(); 
   for(i=0;i<n;i++) 
   scanf("%c",&s[i]); 
   for(i=0;i<n;i++)
   { 
       j=s[i]-'a'; 
	   b[j]++; 
   } 
   for(j=0;j<26;j++)
   { 
       if(b[j]%2!=0)
	   { 
	       k++; 
		   x=j+'a';
		   
	  } 
   } 
   if(k>=2) 
   printf("Impossible\n"); 
   else 
   printf("%d\n",changes(s,x,n)); 
   return 0; 
}  

int changes(char s[],char x,int n) 
{ 
    int i,change=0,j,k; 
	for(i=0;i<n/2;i++)
	{ 
	   if(s[i]==x)
	   { 
	     for(j=i;j<n-i-1;j++) 
		 if(s[n-i-1]==s[j]) 
		 break; 
		 change+=j-i; 
		 for(k=j;k>i;k--) 
		 s[k]=s[k-1]; 
		 s[i]=s[n-i-1]; 
	   }
	   else 
	   { 
	   for(j=n-i-1;j>=i;j--) 
	   if(s[i]==s[j]) 
	   break; 
	   change+=n-i-1-j; 
	   for(k=j;k<n-i-1;k++) 
	   s[k]=s[k+1]; 
	   s[n-i-1]=s[i]; 
	   }
	}  
	return change; 
} 