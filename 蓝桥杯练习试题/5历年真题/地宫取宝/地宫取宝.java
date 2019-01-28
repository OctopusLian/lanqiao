import java.util.Scanner;

public class Main {
	static int p[][] = new int[51][51];
	static int d[][][][] = new int[51][51][13][14];
	static int n;
	static int m;
	static int k;
	static final int c = 1000000007;

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		m = cin.nextInt();
		k = cin.nextInt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				p[i][j] = cin.nextInt();
			}
		}
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				for (int x = 0; x < 13; x++) {
					for (int y = 0; y < 14; y++)
						d[i][j][x][y] = -1;
				}
			}
		}
		d[0][0][0][0] = dfs(0, 0, 0, -1);
		System.out.println(d[0][0][0][0]);
	}

	private static int dfs(int i, int j, int num, int max) {
		if (d[i][j][num][max + 1] != -1) {
			return d[i][j][num][max + 1];
		}
		int t = 0;
		if (i == n - 1 && j == m - 1) {
			if (p[i][j] > max) {
				if (num == k || num == k - 1)
					t++;
			} else {
				if (num == k)
					t++;
			}
			return d[i][j][num][max + 1] = t;
		}
		if (i + 1 < n) {
			if (p[i][j] > max) {
				t += dfs(i + 1, j, num + 1, p[i][j]);
				t %= c;
				t += dfs(i + 1, j, num, max);
				t %= c;
			} else {
				t += dfs(i + 1, j, num, max);
				t %= c;
			}
		}
		if (j + 1 < m) {
			if (p[i][j] > max) {
				t += dfs(i, j + 1, num + 1, p[i][j]);
				t %= c;
				t += dfs(i, j + 1, num, max);
				t %= c;
			} else {
				t += dfs(i, j + 1, num, max);
				t %= c;
			}
		}
		d[i][j][num][max + 1] = t;
		return t;
	}

}
