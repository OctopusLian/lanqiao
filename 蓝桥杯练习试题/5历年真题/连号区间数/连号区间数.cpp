#include <iostream>
using namespace std;
int a[50001];
int main()
{
	int i,j,n,cnt=0;
	int x,y;//最大数和最小数 
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		x=y=a[i];
		for(j=i;j<n;j++)
		{
			x=max(a[j],x);
			y=min(a[j],y);
			if(x-y==j-i)
				cnt++;
		}
	}
	cout<<cnt;
    return 0;
}