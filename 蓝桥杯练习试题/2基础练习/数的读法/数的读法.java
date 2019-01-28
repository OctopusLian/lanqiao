import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String num = in.readLine();
		char[] ch = num.toCharArray();
		getRed(ch,num);
	}
	public static void getRed(char[] ch,String str){
		int numL01 = ch.length;
		String[] numR01 = new String[numL01];
		for(int a = 0;a < numL01;a++){
			numR01[a] = getNum(ch[a] + "");
		}
		int numL02 = 2 * numL01 - 1;
		String[] numR02 = new String[numL02];
		numR02[0] = numR01[0];
		int i01 = 10 - numL01;
		int i02 = 1;
		for(int a = 1;a < numL02;a++){
			if((a%2) == 0){
				numR02[a] = numR01[i02];
				i02++;
			}else{
				numR02[a] = getR(i01);
				i01++;
			}
		}
		String red = numR02[0];
		for(int a = 1;a < numL02;a++){
			if(a%2 == 0){
				if(red.endsWith("ling ")){
					if(getT(numR02[a]))red += numR02[a];
				}else{
					red += numR02[a];
				}
			}else{
				if(red.endsWith("ling ")){
					if(getTR(numR02[a]))red = red.substring(0, red.length() - 5) + numR02[a];
				}else{
					red += numR02[a];
				}
			}
		}
		if(red.endsWith("ling "))red = red.substring(0, red.length() - 5);
		if((str.length() > 8) 
				& (red.startsWith("yi shi "))){
			red = red.substring(3);
		}
		if(red.indexOf(" i wan ")!=-1){
			red = red.replaceFirst(" i wan ", " yi ");
		}else if(red.indexOf(" i ")!=-1){
			red = red.replaceFirst(" i ", " yi ");
		}
		if(str.length() == 6){
			if(red.indexOf("yi shi ")!=-1){
				red = red.replaceFirst("yi shi ", "shi ");
			}
		}
		System.out.println(red);
	}
	public static String getNum(String str){
		String[] num = {"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
		str = num[Integer.parseInt(str)];
		return str;
	}
	public static String getR(int i){
		String[] red = {"shi ","i ","qian ","bai ","shi ","wan ","qian ","bai ","shi ",""};
		return red[i];
	}
	public static boolean getT(String str){
		String[] red = {"yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
		boolean num = false;
		for(int a = 0;a < red.length;a++){
			if(str.equals(red[a]))num = true;
			if(str.equals(red[a]))break;
		}
		return num;
	}
	public static boolean getTR(String str){
		boolean r = false;
		if((str.equals("wan ")) | (str.equals("i ")))r = true;
		return r;
	}
}
