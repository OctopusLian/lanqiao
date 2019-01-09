#include<cstdio>
using namespace std;

int n;
int sum;
bool g[9][9];
bool wh[9];
bool wd[17];
bool wu[17];
bool bh[9];
bool bd[17];
bool bu[17];

void white(int h){
	if(h==n){
		sum++;
	}else{
		for(int i=0;i<n;i++){
			if(!g[h][i])continue;
			if(wh[i])continue;
			if(wd[i+h])continue;
			if(wu[(i-h)+n])continue;
			wh[i]=wd[i+h]=wu[(i-h)+n]=1;
			white(h+1);			
			wh[i]=wd[i+h]=wu[(i-h)+n]=0;
		}
	}
}

void black(int h){
	if(h==n){
		white(0);
	}else{
		for(int i=0;i<n;i++){
			if(!g[h][i])continue;
			if(bh[i])continue;
			if(bd[i+h])continue;
			if(bu[(i-h)+n])continue;
			g[h][i]=0;
			bh[i]=bd[i+h]=bu[(i-h)+n]=1;
			black(h+1);			
			g[h][i]=1;
			bh[i]=bd[i+h]=bu[(i-h)+n]=0;
		}
	}
}

int main(){
	int i;
	int x;
	sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		wh[i]=bh[i]=0;
		wd[i]=bd[i]=0;
		wu[i]=bu[i]=0;
		for(int j=0;j<n;j++){
			scanf("%d",&x);
			g[i][j]=(bool)x;
		}
	}
	for(;i<2*n;i++){
		wd[i]=bd[i]=0;
		wu[i]=bu[i]=0;
	}
	black(0);
	printf("%d\n",sum);
	return 0;
}