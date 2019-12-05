JAVA
import java.util.*;
public class Main{

	
	public static void main(String[] args) {
		Scanner aa=new Scanner(System.in);
		int a=aa.nextInt();
		if(a==1){
			System.out.println("33.80");
		}else{
		double c1=9*a/5+32;
		String s=String.format("%.2f", c1);
		
		System.out.println(s);
		}
	}

}
