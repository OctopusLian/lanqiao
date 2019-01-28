import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main{
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        int a[] = new int[100000];
        int b[] = new int[100000];
        int l1 = s1.length();
        int l2 = s2.length();
        for(int i=0; i<l1; i++){
            a[l1-1-i] = Character.getNumericValue(s1.charAt(i));
        }
        for(int i=0; i<l2; i++){
            b[l2-1-i] = Character.getNumericValue(s2.charAt(i));
        }
        int max = l1>l2?l1:l2;
        int c[] = new int[100000];
        for(int i=0; i<max; i++){
            c[i] = a[i] + b[i];
        }
        for(int i=0; i<max-1; i++){
            if(c[i]>9){
                c[i+1] += c[i]/10;
                c[i] = c[i]%10;
            }
        }
        while(c[max-1]>9){
            c[max] = c[max-1]/10;
            c[max-1] = c[max-1]%10;
            max++;
        }
        for(int i=max-1; i>=0; i--){
            System.out.print(c[i]); 
        }
    }
}
