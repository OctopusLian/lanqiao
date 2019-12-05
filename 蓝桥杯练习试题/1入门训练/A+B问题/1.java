import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main
{
	public static void main(String[] args) throws IOException
	{
		args = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
		System.out.println(Integer.parseInt(args[0])+Integer.parseInt(args[1]));
	}
}
