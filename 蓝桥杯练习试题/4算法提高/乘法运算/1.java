import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		int c1 = scanner.nextInt();
		int c2 = scanner.nextInt();
		String s = String.valueOf(c1 * c2);
		int len = s.length();
		char[] cs = c2 < 10 ? String.valueOf(" " + c2).toCharArray() : String
				.valueOf(c2).toCharArray();
		System.out.println(c1 + "\n\u00D7" + String.valueOf(cs)
				+ "\n\u2501\u2501\u2501");
		if (c2 >= 10) {
			for (int i = cs.length - 1; i >= 0; i--) {
				if (cs[i] != ' ') {
					String x = String.valueOf(c1 * (cs[i] - '0'));
					if (x.equals("0"))  
						x = "00"; 
					for (int j = 1; j < cs.length - i; j++)
						x += " ";
					int l = x.length();
					for (int j = 0; j < len - l; j++)
						x = " " + x;
					System.out.println(x);
				}
			}
			System.out.println("\u2501\u2501\u2501");
		}
		System.out.println(s);
	}
}
