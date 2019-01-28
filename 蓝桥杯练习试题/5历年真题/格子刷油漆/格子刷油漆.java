import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(bfr.readLine());
		long sum=0,mod=1000000007;
		long[] A=new long[n+1];
		long[] B=new long[n+1];
		A[1]=1; A[2]=2;
		B[1]=1; B[2]=6;
		
		int i,j;
		for(i=3;i<=n;i++)
		{
			A[i]=2*A[i-1]%mod;
			B[i]=(2*B[i-1]%mod+2*A[i-2]%mod+B[i-2]*2%mod+2*A[i-2]%mod+2*B[i-2]%mod)%mod;
		}
		sum=4*B[n]%mod;
		for(j=2;j<n;j++)
		{
			sum+=(2*(A[j-1]*2*B[n-j]*2%mod+2*A[n-j]*2*B[j-1]%mod));
			sum%=mod;
		}
		if(n>1) System.out.println(sum);
		else System.out.println(2);
	}

}
