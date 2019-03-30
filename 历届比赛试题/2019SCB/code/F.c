#include<stdio.h>
int main()
{
    int n;
    int sum = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
			
		for ( int weishu = i ; weishu != 0 ; weishu = weishu / 10)
		{
			int yushu = weishu % 10 ;
			if (yushu ==2 || yushu==1 || yushu==0 || yushu==9)
			{
				sum = sum + i ;
				break;
			}
		}
	
    }
    printf("%d\n",sum);

    return 0;
}