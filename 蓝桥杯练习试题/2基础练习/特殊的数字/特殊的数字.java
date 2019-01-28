import java.util.Arrays;
public class Main{
	public static void main(String args[]){
		StringBuffer string = new StringBuffer();
		for(int a=1;a<10;a++){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					if(Math.pow(a, 3)+Math.pow(b, 3)+Math.pow(c,3)==(a*100+b*10+c)){
						string.append(a*100+b*10+c+",");
					}
				}
			}
		}
		String[] str = string.toString().split(",");
		int[] num = new int[str.length];
		for(int i=0;i<str.length;i++){
			num[i] = Integer.parseInt(str[i]);
		}
		Arrays.sort(num);
		for(int i:num){
			System.out.println(i);
		}
	}
}
