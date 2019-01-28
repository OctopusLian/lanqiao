import java.io.*;
public class Main {
	public static void main(String args[])throws Exception{
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		String str1= null;String str2 = null;
		str1 = buf.readLine();
		str2 = buf.readLine();
		
		if(str1.length()==str2.length()){
			if(str1.equals(str2)){
				System.out.println(2);
			}else if(str1.equalsIgnoreCase(str2)){
				System.out.println(3);
			}else{
				System.out.println(4);
			}
		}else{
			System.out.println(1);
		}
	}
}