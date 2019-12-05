#include <iostream>
using namespace std;
int n ;
int m ;
int mm ;
int main()
 {
 	long mm = 0 , t ,p;
	cin >> n ;
	for (int i = 1 ; i <= n ; i ++ )
	{		
		for ( t = i ; t != 0 ; t=t/10)
		{
			p = t % 10 ;
			if (p ==2 ||p==1 || p==0||p==9)
			{
				mm += i ;
				break ;
			}
		}
	}
	cout << mm ;
	return 0;
}

