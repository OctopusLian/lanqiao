#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int GetI(char c)
{
	return c>>4&1?c&15:(c&15)+9; 
}

int main(int argc, char *argv[]) {
	char arr[200001] = {'\0'};
	char brr[400001] = {'\0'};
	int n = 0;
	int i = 0;
	scanf("%d",&n);

	for(i = 0;i < n;i++)
	{
		scanf("%s",arr);
		int m[3] = {1,16,256};
		int len = strlen(arr);
		int j = len-1;
		int a,b,c;
		a = b = c = 0;
		int k = 0,l = 0;
		int count = 0;
		while(j>-1)
		{

			a += (arr[j]>>4&1?arr[j]&15:(arr[j]&15)+9)*m[k]; //个位
			if(k==2||j==0)
			{
				while(a)
				{
					brr[l++] = ((a&7)|48);
					a = a>>3;
					count++;
				}
				while(j!=0&&count<4)
				{
					brr[l++] = '0';
					count++;
				}
				count = 0;
			}
			k = (k+1)%3;
			j--;
		}
		strrev(brr);
		printf("%s\n",brr);
		memset(arr,'\0',(sizeof(char)*200001));
		memset(brr,'\0',(sizeof(char)*400001));
	}
    return 0; 
}
