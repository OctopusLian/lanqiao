#include<iostream>
using namespace std;
#define N 100
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char d[]={'U','R','D','L'};//上右下左 
int main()
{
	int a[N][N],m,n,i,j;
	cin>>m>>n;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	int x,y,k;
	char s;
	cin>>x>>y>>s>>k;
	for(i=0;i<4;i++)
	{
		if(d[i]==s) break;
	} 
	while(k--)
	{
		if(a[x][y])//黑格
			i=(i+1)%4;//右转 
		else//白格 
			i=(i+3)%4;//左转 
		a[x][y]^=1;//黑白互换
		//if(x>0&&y>0&&x<m-1&&y<n-1)
		if(!x&&!i) continue;//不能上
		if(y==n-1&&i==1) continue;//不能右
		if(x==m-1&&i==2) continue;//不能下 
		if(!y&&i==3) continue;//不能左 
		x=x+dx[i],y=y+dy[i];	 
	}
	cout<<x<<" "<<y;
	return 0;
}