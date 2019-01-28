import java.util.Scanner;
public class Main{
        public static void main(String[] args){
        Scanner sc=new Scanner(System.in);  
        fd(sc.nextInt()); 
    }
    
    public static void fd(int n){
        int len=5+4*n;
        String a[][]=new String[len][len];
        int b=len/2;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                a[i][j]=".";
            }}
        for(int i=b-2;i<b+2;i++){
            a[i][b]="$";
            a[b][i]="$";
        }
        for(int m=0;m<n;m++){
            for(int i=b-2-2*m;i<(b+3+2*m);i++){
                 a[b - (4+m*2)][i] = "$";  
                 a[b + (4+m*2)][i] = "$";  
                 a[i][b - (4+m*2)] = "$";  
                 a[i][b + (4+m*2)] = "$";  
            }   
        }
        for(int m=0;m<n;m++){
          for (int i = b - (3+m*2); i <= b + 3+m*2; i++) {  
              a[b - (2+m*2)][i] = "$";  
              a[b + 2+m*2][i] = "$";  
              a[i][b + 2+m*2] = "$";  
              a[i][b - (2+m*2)]= "$";  
          }  
          a[b - (2+m*2)][b - (1+m*2)] = ".";  
          a[b - (2+m*2)][b + 1+m*2] = ".";  
          a[b + 2+m*2][b - (1+m*2)] = ".";  
          a[b + 2+m*2][b + 1+m*2] = ".";  
          a[b - (1+m*2)][b - (2+m*2)] = ".";  
          a[b + 1+m*2][b - (2+m*2)] = ".";  
          a[b - (1+m*2)][b + 2+m*2] = ".";  
          a[b + 1+m*2][b + 2+m*2] = ".";  
      }  
        
    
         for (int i= 0; i < len; i++) {  
                for (int j = 0; j < len; j++) {  
                    System.out.print(a[i][j]);  
                                            
            }
            System.out.println();
        }
    }
}