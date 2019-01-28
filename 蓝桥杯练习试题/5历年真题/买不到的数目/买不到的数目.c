#include<stdio.h>
#define MAXSIZE 1000
int main() {
	int flag[MAXSIZE] = {0};
	int maxunuse[MAXSIZE] = {0};
	int num1, num2, minNum, maxNum, temp, i, count = 0;
	scanf("%d%d", &num1, &num2);
	minNum = ((num1 < num2) ? num1 : num2);
	maxNum = num1 + num2 - minNum;
	for(i = 1; ;i++){
		temp = i * maxNum % minNum;
		if((temp) && flag[temp] == 0){
			flag[temp] = 1;
			maxunuse[temp] = i * maxNum -minNum;
			count++;
			if(count == minNum - 1){
				break;
			}
		}
	}
	printf("%d\n", maxunuse[temp]);
	return 0;
}
