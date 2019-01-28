import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class  Reader11{
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	
	static void init(InputStream input){
		reader=new BufferedReader(new InputStreamReader(input));
		tokenizer=new StringTokenizer("");
	}
	static String next() throws IOException{
		while (!tokenizer.hasMoreElements()) {
			tokenizer =new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	static int nextInt() throws IOException{
		return Integer.parseInt(next());
	}
}

public class Main{

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader11.init(System.in);
		int m=Reader11.nextInt();
		int n=Reader11.nextInt();
		ArrayList<Integer> a=new ArrayList<Integer>();
		for (int i = 1; i < n; i++) {
			a.add(i);
		}
		int k=1;
		int t=a.get(k);
		while (t<=a.size()) {
			int t0=a.get(k+1);
			for (int j = 1; t*j < a.size()+j; j++) {
				a.remove(t*j-j);
			}
			if (a.get(k)==t0) {
			}else {
				k++;
			}
			t=a.get(k);
		}
		int Mj = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a.get(i)>m) {
				Mj=i;
				break;
			}else if(a.get(i)==m){
				Mj=i+1;
				break;
			}
		}
		System.out.println(a.size()-Mj);
	}

}
