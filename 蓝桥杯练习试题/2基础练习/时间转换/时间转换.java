import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String args[]) throws NumberFormatException, IOException{
        BufferedReader strin = new BufferedReader(new InputStreamReader(System.in));
        String st = strin.readLine();
        String str[]  = st.split(" ");
        long x = Integer.parseInt(str[0]);
        int h = (int)x/3600;
        int m = (int)x%3600/60;
        int s = (int)x%60;
        System.out.println(h+":"+m+":"+s);
    }
}