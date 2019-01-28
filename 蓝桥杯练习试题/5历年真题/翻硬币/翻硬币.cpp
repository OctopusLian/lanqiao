#include <iostream>
using namespace std;
char reverse(char c)
{
    if(c=='*')
		c='o';
	else
		c='*';
	return c;
}

int main()
{
    char a[1000],b[1000];
	cin>>a>>b;
	int move=0;
	for(int i=0;a[i]!='\0';i++)
	{
	    if(a[i]!=b[i])
		{
	        a[i]=reverse(a[i]);
	        a[i+1]=reverse(a[i+1]);
			move++;
		}
	}
	cout<<move<<endl;
    return 0;
}
