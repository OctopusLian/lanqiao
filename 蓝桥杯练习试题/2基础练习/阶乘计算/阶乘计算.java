import java.math.BigInteger;
import java.util.*;
public class Main{
	protected static ArrayList table = new ArrayList();
	static {
		table.add(BigInteger.valueOf(1));
	}
	public static synchronized BigInteger factorial(int x) {
		for (int size = table.size(); size <= x; size++) {
			BigInteger lastfact = (BigInteger) table.get(size - 1);
			BigInteger nextfact = lastfact.multiply(BigInteger.valueOf(size));
			table.add(nextfact);
		}
		return (BigInteger) table.get(x);
	}
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		System.out.print(factorial(n));
	}
}