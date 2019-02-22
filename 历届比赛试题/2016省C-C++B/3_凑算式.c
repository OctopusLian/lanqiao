#include<stdio.h>
int main()
{
    int A,B,C,D,E,F,G,H,I;  //九个不重复的数字 
    
    int sum1,sum2,sum3,sum4;  //四个多项式 
    
    int ans;  //统计解法 
    
    ans=0;
    for(A=1;A<=9;++A){
        
        for(B=1;B<=9;++B){
            if(B==A)continue;
            for(C=1;C<=9;++C){
                if(C==A||C==B)continue;
                for(D=1;D<=9;++D){
                    if(D==A||D==B||D==C)continue;
                    for(E=1;E<=9;++E){
                        if(E==A||E==B||E==C||E==D)continue;
                        for(F=1;F<=9;++F){
                            if(F==A||F==B||F==C||F==D||F==E)continue;
                            for(G=1;G<=9;++G){
                                if(G==A||G==B||G==C||G==D||G==E||G==F)continue;
                                for(H=1;H<=9;++H){
                                    if(H==A||H==B||H==C||H==D||H==E||H==F||H==G)continue;
                                    for(I=1;I<=9;++I){
                                        if(I==A||I==B||I==C||I==D||I==E||I==F||I==G||I==H)continue;
                                        
                                        sum1=A*C*(G*100+H*10+I);
                                        sum2=B*(G*100+H*10+I);
                                        sum3=(D*100+E*10+F)*C;
                                        sum4=10*C*(G*100+H*10+I);
                                        //注意，要将题中的等式通分 
                                        if(sum1+sum2+sum3==sum4){
                                            
                                            ++ans;
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}