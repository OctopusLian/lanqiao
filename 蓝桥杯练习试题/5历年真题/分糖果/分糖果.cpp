#include <iostream>
using namespace std;

int a[100];                            // 小朋友人数<100

bool notEqual(int n)
{
	for (int i = 1; i < n; ++i)
		if (a[0] != a[i])
			return true;
	return false;
}

int main()
{
	int i, n, t, s = 0;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	while ( notEqual(n) )
	{
		a[0] /= 2;
		t = a[0];
		for (i = 1; i < n; ++i)
		{
			a[i] /= 2;
			a[i-1] += a[i];
		}
		a[n-1] += t;
		for (i = 0; i < n; ++i)
			if (a[i] % 2)              // 奇数个颗糖
				++a[i], ++s;
	}
	cout << s << '\n';                 // 补发糖果总数数
	return 0;
}
