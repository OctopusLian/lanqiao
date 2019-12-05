#include <iostream>
#include <stdio.h>
#include <malloc.h>

#include<cmath>

using namespace std;
int main()
{
	int num = 0;
	for (int i = 1; i < 2019; i++)
	{
		for (int j = i; j < 2019; j++)
		{
			for (int m = j; m < 2019; m++)
			{
				if (i + j + m == 2019
					&& i % 10 != 2 && i % 10 != 4
					&& j % 10 != 2 && j % 10 != 4
					&& m % 10 != 2 && m % 10 != 4
					&& i != j && i != m && j != m)
				{
					num++;
				}
			}
		}
	}
	cout << num << endl;
	system("pause");
}

