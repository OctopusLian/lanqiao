import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		String s=bf.readLine();
		int n=Integer.parseInt(s);
		String a="A";
		f(n,a,1);
	}

	private static void f(int n, String a, int i) {
		if(n==i){
			System.out.println(a);
			return;
		}
		else {
			a=a+String.valueOf((char)(i+65))+a;
			if(i==n){
				System.out.println(a);
			return;
			}
		}
		//while(i<n)
		f(n,a,i+1);
	}
}