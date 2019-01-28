import java.io.*;

public class Main {
	static int count2;
	static int[] arr;
	static boolean bl;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String str[] = br.readLine().split(" ");

		arr = new int[n];
		for (int i = 0; i < arr.length; i++)
			arr[i] = Integer.parseInt(str[i]);

		func();
	}

	public static void func() {

		if (ifSame()) {
			System.out.print(count2);
			return;
		}

		ifEven();

		if (ifSame()) {
			System.out.print(count2);
			return;
		}

		int temp = arr[arr.length - 1];
		for (int a = arr.length - 1; a >= 0; a--) {
			if (a > 0) {
				arr[a] = arr[a] / 2 + arr[a - 1] / 2;
			}
			if (a == 0) {
				arr[0] = arr[0] / 2 + temp / 2;
			}
		}

		func();
	}

	public static void ifEven() {
		for (int a = 0; a < arr.length; a++) {
			if (arr[a] % 2 == 0) {
				continue;
			} else {
				arr[a] += 1;
				count2++;
			}
		}
	}

	public static boolean ifSame() {
		int temp = arr[0];
		int count1 = 0;
		for (int a = arr.length - 1; a > 0; a--) {
			if (temp == arr[a]) {
				count1++;
			}
		}
		if (count1 == arr.length - 1) {
			bl = true;
		}
		return bl;
	}
}