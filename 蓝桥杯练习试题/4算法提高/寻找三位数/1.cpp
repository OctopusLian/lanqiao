#include <cstdlib>
  #include <iostream>
  
  using namespace std;
  
  int main(int argc, char *argv[])
  {
      int i,j,k,n,a[9],num;
      for(i=123;i<=327;i++)
     {   n=0;        
         if(i/100!=i%100/10&&i/100!=i%10&&i%100/10!=i%10&&i%100/10!=0&&i%10!=0)
         {
             for(j=1;j<=3;j++)
             {
                 a[n++]=j*i/100;
                 a[n++]=j*i%100/10;
                 a[n++]=j*i%10;
             }
             
             for(j=0;j<9;j++)
             {   
                 num=0;
                 if(a[j]!=0)            
                   {  
                       for(k=j+1;k<9;k++)
                     {
                         if(a[j]==a[k])
                         {
                             num++;
                           break;
                         }
                                                                     
                     }
                     if(num>0)
                        break;  
                  } 
                   else 
                   {
                       num++;
                       break;
                  }                                             
             }             
             if(num==0)
              {  
                 for(j=1;j<10;j++)
                 {
                     cout<<a[j-1];
                     if(j%3==0)
                    cout<<" ";
                }
                 cout<<endl; 
               }     
         }
         
     }
     return 0;
 }
