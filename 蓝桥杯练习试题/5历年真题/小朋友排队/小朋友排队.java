import java.util.Scanner;
 
public class Main {
 
    final static int N2 = 1048576;//N2 = 2^20
    final static int N = 2*N2;
    public static int[] T;
     
    public static void main(String[] args) {
         
        T = new int[22];
        T[0] = N;
        for(int i = 1; i < 22; i ++){
            T[i] = T[i-1] >> 1;
        }
         
        long ans = 0;
        int[] Tree01 = new int[N + 1];
        int[] Tree02 = new int[N + 1];
         
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] num = new int[size];
        int[] leftHigher = new int[size];
        int[] rightLower = new int[size];
        for(int i = 0; i < size; i ++)
            num[i] = sc.nextInt();
        sc.close();
         
        for(int i = 0; i < size; i ++)
            leftHigher[i] = rightLower[i] = 0;
         
        for(int i = 0; i < N + 1; i ++)
            Tree01[i] = Tree02[i] = 0;
         
       
         
        for(int i = 0; i < size; i ++){
             
            int count = 0;
            int n = num[i] + 1;
            int start = 0;
            int temp;
             
            for(int j = 1; j < 22; j ++){
                 
                if((n&T[j]) != 0){
                    //n:14 count = [0,7] + [8,11] + [12,13]
                    temp = getPosition(start, j, T[j]);
                    count += Tree01[temp];
//                  System.out.println("" + start + " " + j + T[j] + " " + count + " " + temp);
                    start += T[j];
                }
                 
            }
             
            n = num[i];
             
            for(int j = 1; j < 21; j ++){
                Tree01[n + fun1(j-1)] ++;
//              System.out.print(n+fun1(j-1) + " ");
                n = n >> 1;
            }
            leftHigher[i] =  i - count;
//          System.out.println("" + leftHigher[0] + leftHigher[1] + leftHigher[2]);
             
        }
         
        
        for(int i = 0; i < size; i ++){
             
            int count = 0;
            int n = num[size-1 - i] + 1;
            int start = 0;
            int temp;
             
            for(int j = 1; j < 22; j ++){
                 
                if((n&T[j]) != 0){
                    //n:14 count = [0,7] + [8,11] + [12,13]
                    temp = getPosition(start, j, T[j]);
                    count += Tree02[temp];
//                  System.out.println("" + start + " " + j + T[j] + " " + count + " " + temp);
                    start += T[j];
                }
                 
            }
             
            n = num[size-1 - i];
             
            for(int j = 1; j < 21; j ++){
                Tree02[n + fun1(j-1)] ++;
//              System.out.print(n+fun1(j-1) + " ");
                n = n >> 1;
            }
            rightLower[i] = count - Tree02[num[size-1 - i]] + 1;
//          System.out.println("" + leftHigher[0] + leftHigher[1] + leftHigher[2]);
             
        }
//      
//      for(int i = 0; i < size; i ++){
//          System.out.print(leftHigher[i] + " ");
//      }
//      
//      System.out.println();
//      
//      for(int i = 0; i < size; i ++){
//          System.out.print(rightLower[i] + " ");
//      }
         
        for(int i = 0; i < size; i ++){
            long temp = leftHigher[i] + rightLower[size-1 - i];
            ans += (temp+1)*temp/2;
        }
        System.out.println(ans);
         
    }
     
    public static int countTime(int val){
         
        for(int i = 0;;i++){
            if(val >> i < 2) return i;
        }
         
    }
     
    public static int fun1(int radix){
         
        return N - (N >> radix);
         
    }
     
    public static int getPosition(int min, int add, int T){
         
        if(add == 1) return min;
        if(min == 0)return fun1(21-add);
        return fun1(21-add) + min /(T);
         
    }
     
}
