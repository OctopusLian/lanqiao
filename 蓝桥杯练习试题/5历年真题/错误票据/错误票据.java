import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) throws Exception {
		int duan = 0;
		int chong = 0;
		List<Integer> list = new ArrayList();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int len = Integer.parseInt(line);
		for(int i = 0; i < len; i++)
		{
			String l = br.readLine();
	
			String[] s = l.split(" ");
			for(int j = 0; j < s.length; j++)
			{
				list.add(Integer.parseInt(s[j]));
			}
		}
		for(int i = 0 ; i < list.size(); i++)
		{
			for(int j = 0; j < list.size(); j++)
			{
				int a = list.get(i);
				int b = list.get(j);
				int temp = 0;
				if(a < b)
				{
					temp = a;
				//	a = b;
				//	b = temp;
					list.set(i, b);
					list.set(j, temp);
				}
			}
		}
	
		for(int i = 0 ; i < list.size() - 1; i++)
		{
				int a = list.get(i);
				int b = list.get(i + 1);
				if(a == b)
					chong = a;
				if(b - a > 1)
					duan = b -1;
		}
		System.out.println(duan + " " + chong);
	}
}