import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
	public static void main(String[] args) throws IOException{
	    BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
	    String s=reader.readLine();
	    int n=Integer.valueOf(s);
	    int f1=1,f2=1,f3=0;
	    if(n<3){
	    	System.out.print("1");
            return;
        }
	    for(int i=3;i<=n;i++)
	    {
            if(f1>10007)f1=f1%10007;
	            if(f2>10007)f2=f2%10007;
	                f3=f1+f2;
	                f1=f2;
	                f2=f3;
	    }
	    System.out.print(f3%10007);
	}
	    
}