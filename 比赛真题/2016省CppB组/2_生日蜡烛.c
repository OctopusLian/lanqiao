#include<stdio.h>
int main()
{
    int newage,oldage,sum;  //newage为开始过生日party的年龄，oldage为现在的年龄 
    for(newage=0;newage<150;++newage){
        sum=0;
        for(oldage=newage;oldage<150;++oldage){
            sum=sum+oldage;
            if(sum==236)  //判断吹灭的蜡烛总数 
                printf("%d,%d\n",newage,oldage);
        }
    }
    return 0;
}