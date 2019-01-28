#include<stdio.h>

int h[100100];
int un[100100];

int b[1000100];
int reb[1000100];

int Lowbit(int x){
    return x&(x^(x-1));
}

int sum(int bit[], int idx){
	int ret = 0;
	while(idx > 0){
		ret += bit[idx];
		idx -= Lowbit(idx);
	}
	return ret;
}

void add(int bit[], int idx, int val){
	while(idx < 1000100){
		bit[idx] += val;
		idx += Lowbit(idx);
	}
}

long long uVal[100100];

int main(void){
	int n, i;
	scanf("%d", &n);
	uVal[0] = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &h[i]);
		h[i]++;
		uVal[i + 1] = uVal[i] + i + 1;
		
		un[i] += i - sum(b, h[i]);
		add(b, h[i], 1);
	}
	long long ans = 0;
	for(i = n - 1; i >= 0; i--){
		un[i] += sum(reb, h[i] - 1);
		add(reb, h[i], 1);
		
		ans += uVal[un[i]];
	}
	printf("%I64d\n", ans);
	return 0;
}