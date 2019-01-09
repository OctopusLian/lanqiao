#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    char s[100000];
    while(cin>>n)
    {
        int k=0;
        if(n==0)
        {
            cout<<0;
        }
        else
        {
           while(n!=0)
           {
               if(n%16>=10)
               {
                   s[k++]='A'+n%16-10;
               }
               else
               {
                   s[k++]='0'+n%16;
               }
               n=n/16;
           }
           for(int i=k-1;i>=0;i--)
           {
               cout<<s[i];
           }
        }
       cout<<endl;
    }
    return 0;
}