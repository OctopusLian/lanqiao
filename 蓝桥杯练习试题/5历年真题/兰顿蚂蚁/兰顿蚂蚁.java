import java.io.*;

public class Main {
	static int n, m;
	static int s, e;
	static char[] chs = { 'L', 'U', 'R', 'D', 'L' };
	static int count = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s1[] = br.readLine().split(" ");
		n = Integer.parseInt(s1[0]);
		m = Integer.parseInt(s1[1]);

		int[][] arr = new int[n][m];
		for (int a = 0; a < n; a++) {
			String str[] = br.readLine().split(" ");
			for (int b = 0; b < m; b++) {
				arr[a][b] = Integer.parseInt(str[b]);
			}
		}

		int x, y;
		String s2[] = br.readLine().split(" ");
		x = Integer.parseInt(s2[0]);
		y = Integer.parseInt(s2[1]);

		char dec = s2[2].charAt(0);

		int z;
		z = Integer.parseInt(s2[3]);

		s = x;
		e = y;
		while (count < z) {
			if (arr[s][e] == 1) {
				for (int i = 0; i < chs.length; i++) {
					if (dec == chs[i]) {
						dec = chs[i + 1];
						break;
					}
				}
				arr[s][e] = 0;
				func(dec, s, e);

			}

			if (arr[s][e] == 0) {
				for (int j = 1; j < chs.length; j++) {
					if (dec == chs[j]) {
						dec = chs[j - 1];
						break;
					}
				}
				arr[s][e] = 1;
				func(dec, s, e);

			}
		}
		System.out.print(s + " " + e);
	}

	public static void func(char dec, int x, int y) {
		if (dec == 'L') {
			e -= 1;
			count++;
		}
		if (dec == 'U') {
			s -= 1;
			count++;
		}
		if (dec == 'R') {
			e += 1;
			count++;
		}
		if (dec == 'D') {
			s += 1;
			count++;
		}
	}
}