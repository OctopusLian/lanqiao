public class Main
{
	public static void main(String[] args)
	{
		for(int i = 1001; i <= 9999; i++)
			if(isP(i))
				System.out.println(i);
	}

	public static boolean isP(int n)
	{
		int s = 0;
		int p = n;
		while (n>0)
		{
			s = s * 10 + n % 10;
			n /= 10;
		}
		return s == p;
	}
}