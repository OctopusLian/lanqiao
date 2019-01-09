import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		printToHexString(buf.readLine());
	}
	
	public static void printToHexString(String s) {
		StringBuffer st = new StringBuffer();
		int n = Integer.valueOf(s);
		if(n == 0) {
			System.out.println(0);
			return;
		}
		int m;
		while(n > 0) {
			m = n % 16;
			n = n / 16;
			switch(m) {
			case 0:
				st.insert(0, "0");
				break;
			case 1:
				st.insert(0, "1");
				break;
			case 2:
				st.insert(0, "2");
				break;
			case 3:
				st.insert(0, "3");
				break;
			case 4:
				st.insert(0, "4");
				break;
			case 5:
				st.insert(0, "5");
				break;
			case 6:
				st.insert(0, "6");
				break;
			case 7:
				st.insert(0, "7");
				break;
			case 8:
				st.insert(0, "8");
				break;
			case 9:
				st.insert(0, "9");
				break;
			case 10:
				st.insert(0, "A");
				break;
			case 11:
				st.insert(0, "B");
				break;
			case 12:
				st.insert(0, "C");
				break;
			case 13:
				st.insert(0, "D");
				break;
			case 14:
				st.insert(0, "E");
				break;
			case 15:
				st.insert(0, "F");
				break;
			}
		}
		System.out.println(st);
	}
}