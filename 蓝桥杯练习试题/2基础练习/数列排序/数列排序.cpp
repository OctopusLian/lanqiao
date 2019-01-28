#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int a[205];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,cmp);
        cout<<a[0];
        for(int i=1;i<n;i++)
        {
            cout<<' '<<a[i];
        }
        cout<<endl;
    }
    return 0;
}