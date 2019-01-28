import java.util.Scanner;

public class Main {

	static int n,k,T;
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		n = scan.nextInt();
		k = scan.nextInt();
		T = scan.nextInt();
		
		int t = 0;
		long sum = 1;
		long tn = n;
		
		while(t<T-1){
			long temp;
			if(tn%2==0)
				temp = (1+(tn/2%k*((1+tn)%k))%k)%k;
			else
				temp = (1+(tn%k*((1+tn)/2%k))%k)%k;
			sum += temp;
			tn += n;
			t++;
		}
		System.out.println(sum);

	}

}