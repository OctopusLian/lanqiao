#include <iostream>
using namespace std;
int main()
{
	int n,H,M,S,t;
	cin>>n;
	H=n/3600;
	t=n%3600;
	M=t/60;
	S=t%60;
	cout<<H<<":"<<M<<":"<<S;	
}