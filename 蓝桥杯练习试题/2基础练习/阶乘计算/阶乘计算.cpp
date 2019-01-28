#include <stdio.h>
#include <string.h>
#define MAX 10000
#define mod 10000
#define baselen 4
#define in(a) scanf("%d",&a)
#define out1(a) printf("%d",a)
#define out2(a) printf("%04d",a)
typedef int type;
struct bint{
	type dig[MAX], len;
	bint(){len = 0, dig[0] = 0;}
};
void by(bint a, type b, bint& c){
	type i, carry;
	for( i = carry = 0; i <= a.len || carry; i++){
		if( i <= a.len ) carry += b*a.dig[i];
		c.dig[i] = carry%mod;
		carry /= mod;
	}
	i--;
	while( i && !c.dig[i] )i--;
	c.len = i;
}
bool input(bint& a){
	type i, j, w, k, p;
	char data[MAX*baselen+1];
	if(scanf("%s",data)==EOF)return false;
	w = strlen(data) - 1, a.len = 0;
	for(p=0;p<=w&&data[p]=='0';p++);
	while(1){
		i = j = 0, k = 1;
		while(i<baselen&&w>=p){
			j = j+ (data[w--] - '0')*k;
			k *= 10, i++;
		}
		a.dig[a.len++] = j;
		if(w<p)break;
	}
	a.len--;
	return true;
}
void output(bint& a){
	type i;
	i = a.len - 1;
	out1(a.dig[a.len]);
	while(i>=0)out2(a.dig[i--]);
}
void give(type a, bint& b){
	b.dig[0] = a%mod;
	a /= mod;
	if(a>0)b.dig[1] = a, b.len = 1;
	else b.len = 0;
}
int main()
{
	bint a;int b,i;scanf("%d",&b);give(1,a);
	for(i=2;i<=b;i++)by(a,i,a);
	output(a);printf("\n");
	return 0;
}
