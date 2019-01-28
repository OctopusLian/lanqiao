import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	static int n;
	static int sum = 0;
	static int a[];
	static Edge p[];

	public static void main(String[] args) throws Exception {

		BufferedReader buf = new BufferedReader(
				new InputStreamReader(System.in));
		String read[] = buf.readLine().split("\\s+");
		n = Integer.parseInt(read[0]);
		int m = Integer.parseInt(read[1]);

		p = new Edge[m];
		a = new int[n];

		int s, e, w, t;
		for (int i = 0; i < m; i++) {
			read = buf.readLine().split("\\s+");
			s = Integer.parseInt(read[0]) - 1;
			e = Integer.parseInt(read[1]) - 1;
			w = Integer.parseInt(read[2]);
			p[i] = new Edge(s, e, w);
		}

		java.util.Arrays.sort(p);

		boolean flag = false;
		init();
		for (int i = 0; i < m; i++) {

			flag = false;
			s = p[i].s;
			e = p[i].e;

			if (!isConnect(s, e)) {
				flag = true;
				union(s, e);
			}

			while (i < m - 1 && p[i].w == p[i + 1].w) {
				s = p[i + 1].s;
				e = p[i + 1].e;
				if (flag && !isConnect(s, e))
					union(s, e);
				if (!flag && !isConnect(s, e)) {
					flag = true;
					union(s, e);
				}
				i++;
			}
			if (flag)
				sum++;

		}

		System.out.println(sum);

	}

	private static boolean isConnect(int i, int j) {

		if (find(i) == find(j))
			return true;
		return false;
	}

	private static void init() {

		for (int i = 0; i < n; i++)
			a[i] = i;

	}

	private static void union(int x, int y) {

		a[find(x)] = find(y);

	}

	private static int find(int x) {

		if (a[x] == x)
			return x;
		a[x] = find(a[x]);
		return a[x];
	}
}

class Edge implements Comparable<Edge> {

	int s;
	int e;
	int w;

	public Edge(int s, int e, int w) {
		super();
		this.s = s;
		this.e = e;
		this.w = w;
	}

	@Override
	public int compareTo(Edge p) {

		if (this.w < p.w)
			return 1;
		else if (this.w > p.w)
			return -1;
		return 0;
	}

}