#include <iostream>
#include <stdio.h>
#include <malloc.h>

#include<cmath>

using namespace std;



int main()

{

	int n , m , q , temp;

	cin >> n;



	int *input = (int *)malloc(n*sizeof(int));



	for (int i = 0; i < n; i++)

	{

		cin >> input[i];

	}



	for (int i = 0, j = 0; i < n; i += pow(2, j))

	{

		m = j;

		j++;

	}



	int * sum = (int*)malloc(m * sizeof(int));



	for (int i = 0 , s = 0; i <= m; i++)

	{

		sum[i] = 0;

		for (int j = 0; j < pow(2, i); j++ , s++)

		{

			sum[i] += input[s];

		}

	}



	temp = sum[0];



	for (int i = 0; i <= m; i++)

	{

		if (temp < sum[i])

		{

			temp = sum[i];

			q = i + 1;

		}

	}



	cout << q << endl;

}

