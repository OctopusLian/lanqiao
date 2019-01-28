import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader bufferedReader = new BufferedReader(
				new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		List<String> list_5 = new ArrayList<String>();
		List<String> list_6 = new ArrayList<String>();
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				for (int k = 0; k <= 9; k++)
				{
					if (2 * i + 2 * j + k == n)
					{
						list_5.add(i + "" + j + "" + k + "" + j + "" + i + "");
					}
					if (2 * i + 2 * j + 2 * k == n)
					{
						list_6.add(i + "" + j + "" + k + "" + k + "" + j + ""
								+ i + "");
					}
				}
			}
		}
		list_5.addAll(list_6);
		for (String string : list_5)
		{
			System.out.println(string);
		}
	}
}
