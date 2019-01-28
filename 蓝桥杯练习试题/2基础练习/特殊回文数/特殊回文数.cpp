#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c,t;
	cin>>n;
	for(a=1;a<10;a++)
	for(b=0;b<10;b++)
	for(c=0;c<10;c++)
	{
		t=a*10001+b*1010+c*100;
		if(2*a+2*b+c==n)
			cout<<t<<endl;	
	}
	for(a=1;a<10;a++)
	for(b=0;b<10;b++)
	for(c=0;c<10;c++)
	{
		t=a*100001+b*10010+c*1100;
		if(2*a+2*b+2*c==n)
			cout<<t<<endl;	
	}
	return 0;
}