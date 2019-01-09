import java.io.BufferedInputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public void work() {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int cas;
		cas = cin.nextInt();
		int s[] = new int[200000 * 4 + 10];
		int ss[] = new int[200000 * 4 / 3 + 10];
		int dep, ndep, turn;
		
		while (cas -- > 0) {
			String st = cin.next();
			dep = 0;
			for (int i = 0; i < st.length(); ++i) {
				char c = st.charAt(i);
				if (c >= 'A' && c <= 'Z')
					turn = 10 + (c - 'A');
				else
					turn = c - '0';
				for (int j = 3; j >= 0; --j) 
					s[dep ++] = turn >> j & 1;
			}
			ndep = 0;
			for (int i = dep - 1; i >= 0; i -= 3) {
				turn = 0;
				for (int j = 0; j < 3 && i - j >= 0; ++j) 
					turn += s[i - j] * (1 << j);
				ss[ndep ++] = turn;
			}
			while (ndep > 1 && ss[ndep - 1] == 0)
				-- ndep;
			for (int i = ndep - 1; i >= 0; -- i)
				out.print(ss[i]);
			out.println("");
		}
		out.close();
	}

	public static void main(String[] args) {
		Main e = new Main();
		e.work();
	}

}