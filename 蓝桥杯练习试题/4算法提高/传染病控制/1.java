import java.util.Scanner;

public class Main {
		
	
		public static void main(String args[]){
			double a;
			Scanner aa=new Scanner(System.in);
			int n=aa.nextInt();
		     double	r=0.1;
			a=(double) Math.pow(1+r, n);
			   String s = String.format("%.2f", a);
               System.out.println(s);
			
		}
}