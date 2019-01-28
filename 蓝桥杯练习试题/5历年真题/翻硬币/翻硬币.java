import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static int cnt = 0;
	
	public static void reverse(char[] origin, int k) {
		origin[k] = (origin[k] == '*') ? 'o' : '*';
		origin[k+1] = (origin[k+1] == '*') ? 'o' : '*';
		++cnt;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] origin = br.readLine().toCharArray();
		char[] target = br.readLine().toCharArray();
		int k = 0;
		
		while(k < target.length)
			if(k+1 < target.length) {
				if(origin[k] != target[k] && origin[k+1] == target[k+1]) {
					reverse(origin, k);
					k = k+1;
				} else if(origin[k] != target[k] && origin[k+1] != target[k+1]) {
					reverse(origin, k);
					k = k+2;
				} else if(origin[k] == target[k] && origin[k+1] == target[k+1])
					k = k+2;
				else
					k = k+1;
			} else
				k = k+1;
		System.out.println(cnt);
	}

}
