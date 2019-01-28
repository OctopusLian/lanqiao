import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader bfr = new BufferedReader(
				new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(bfr.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int m = Integer.parseInt(tok.nextToken());
		int i, count = 0;
		ArrayList<Integer>[] way = new ArrayList[n];
		
		for (i = 0; i < n; i++)
			way[i] = new ArrayList<Integer>();
		
		for (i = 0; i < m; i++) {
			tok = new StringTokenizer(bfr.readLine());
			int x = Integer.parseInt(tok.nextToken()) - 1;
			int y = Integer.parseInt(tok.nextToken()) - 1;
			way[x].add(y);
			way[y].add(x);
		}

		for (i = 0; i < n; i++) {
			int a = i, ll = way[i].size();
			for (int ii = 0; ii < ll; ii++) {
				int aa = way[a].get(ii);
				int lll = way[aa].size();
				for (int iii = 0; iii < lll; iii++) {
					int aaa = way[aa].get(iii);
					if (aaa == a)
						continue;
					count += way[aaa].size();
					count--;
					
				}
			}
		}
		System.out.println(count);
	}
}
