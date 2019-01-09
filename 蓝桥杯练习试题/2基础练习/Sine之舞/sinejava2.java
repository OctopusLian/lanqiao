import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		String string = f(n, 1, 1);
		System.out.println(string);
	}

	private static String f1(int n, int i, int j) {
		if (i == n)
			return "sin(" + j + ")";
		if (i % 2 == 0)
			return "sin(" + i + "+" + f1(n, i + 1, j + 1) + ")";
		else
			return "sin(" + i + "-" + f1(n, i + 1, j + 1) + ")";
	}

	private static String f(int n, int i, int j) {
		if (i == n)
			return f1(n, i, j) + "+" + i;
		return "(" + f(n, i + 1, j) + ")" + f1(n, i, j) + "+" + i;
	}
}
