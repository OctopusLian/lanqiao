import java.io.*;
public class Main
{
     private static int maxSubArray(int n,int a[])
      {
            int b=0,sum=-10000000;
            for(int i=0;i<n;i++)
            {
                  if(b>0) b+=a[i];
                  else b=a[i];
                  if(b>sum) sum=b;
            }
            return sum;  
      }
      private static int maxSubMatrix(int n,int m,int[][] array)
      {
            int i,j,k,max=0,sum=-100000000;
            int b[]=new int[501];
            for(i=0;i<n;i++)
            {
                  for(k=0;k<m;k++)
                  {
                        b[k]=0;
                  }
                  for(j=i;j<n;j++)
                  {
                        for(k=0;k<m;k++)
                        {
                              b[k]+=array[j][k];
                        }
                        max=maxSubArray(k,b);  
                        if(max>sum)
                        {
                                sum=max;
                        }
                  }
            }
            return sum;
      }
      public static void main(String args[]) throws IOException
      {
           BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
           String s1[]=bf.readLine().split(" ");
            int n=Integer.parseInt(s1[0]), m=Integer.parseInt(s1[1]);
            int[][] array=new int[501][501];  
                       for(int i=0;i<n;i++)
                       {
                    	   String s2[]=bf.readLine().split(" ");
                                  for(int j=0;j<m;j++)
                                  {
                                             array[i][j]=Integer.parseInt(s2[j]);
                                  }
                       }
                       System.out.println(maxSubMatrix(n,m,array));
            }
      }
