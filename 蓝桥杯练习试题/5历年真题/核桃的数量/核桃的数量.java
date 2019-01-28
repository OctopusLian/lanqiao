import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str[] = br.readLine().split(" ");

		int[] arr = new int[3];
		for (int a = 0; a < arr.length; a++) {
			arr[a] = Integer.parseInt(str[a]);
		}
		for (int a = 1; a < 27000; a++) {
			if (a % arr[0] == 0 && a % arr[1] == 0 && a % arr[2] == 0) {
				System.out.print(a);
				break;
			}
		}
	}
}