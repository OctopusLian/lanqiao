import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str[] = br.readLine().split(" ");

		int Fir = Integer.parseInt(str[0]);
		int Sec = Integer.parseInt(str[1]);
		int[][] Mat = new int[Fir][Fir];
		int[][] MatPro = new int[Fir][Fir];
		for (int row_1 = 0; row_1 < Fir; row_1++) {
			String input[] = br.readLine().split(" ");
			for (int row_2 = 0; row_2 < Fir; row_2++) {
				Mat[row_1][row_2] = Integer.parseInt(input[row_2]);
			}
		}
		func(MatPro, Mat, Fir, Sec);
	}

	public static void func(int[][] MatPro, int[][] Mat, int a, int b) {
		int[][] tag = new int[a][a];
		for (int x = 0; x < a; x++) {
			for (int y = 0; y < a; y++) {
				tag[x][y] = Mat[x][y];
			}
		}

		if (b == 0) {
			for (int x = 0; x < a; x++) {
				for (int y = 0; y < a; y++) {
					if (x == y) {
						MatPro[x][y] = 1;
					} else {
						MatPro[x][y] = 0;
					}
					System.out.print(MatPro[x][y] + " ");
				}
				System.out.println();
			}
		}

		if (b != 0) {
			for (int p = 1; p < b; p++) {
				for (int x = 0; x < a; x++) {
					for (int y = 0; y < a; y++) {
						int pro = 0;
						for (int z = 0; z < a; z++) {
							pro += Mat[x][z] * tag[z][y];
							MatPro[x][y] = pro;
						}
					}
				}
				for (int x = 0; x < a; x++) {
					for (int y = 0; y < a; y++) {
						tag[x][y] = MatPro[x][y];
					}
				}
			}
			for (int x = 0; x < a; x++) {
				for (int y = 0; y < a; y++) {
					System.out.print(tag[x][y] + " ");
				}
				System.out.println();
			}
		}
	}
}
