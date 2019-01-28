#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    double x1,x2,y1,y2;
    double q1,q2,w1,w2;
    while(cin>>x1>>y1>>x2>>y2>>q1>>w1>>q2>>w2)
    {
        double xx=max(min(x1,x2),min(q1,q2));
        double yy=max(min(y1,y2),min(w1,w2));
        double xxup=min(max(x1,x2),max(q1,q2));
        double yyup=min(max(y1,y2),max(w1,w2));
        if(xxup>xx)
        printf("%.2f\n",fabs((xx)-(xxup))*fabs((yy)-(yyup)));
        else printf("0.00\n");
    }

}