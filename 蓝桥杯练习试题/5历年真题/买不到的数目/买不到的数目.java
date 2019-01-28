import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Main {
    public static void main(String[] args) throws Throwable {
        BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in));
         String strNum = buf.readLine();
         String[] num = strNum.split(" ");
         buf.close();
         int a, b;
         a = Integer.valueOf(num[0]);
         b = Integer.valueOf(num[1]);
        if (a > b) {
            int tem = a;
            a = b;
            b = tem;
        }
        int c = a * b;
        int tem = c;
        while (tem > 0) {
            if (tem % a == 0)
                tem = --c;
            else if (tem % b == 0)
                tem = --c;
            else
                tem -= b;
        }
        System.out.println(c);
    }
 
}