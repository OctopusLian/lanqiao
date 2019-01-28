import java.io.*;
public class Main{
	public static void main(String args[])throws Exception{
		int n;
		int sum=0;
		String str=null;
		String str2=null;
		BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));

		str=buf.readLine();
		n=Integer.parseInt(str);
		
		str2=buf.readLine();
		String a[]=str2.split(" ");
		int array2[]=new int[n];
		for(int i=0;i<n;i++){
		
			array2[i]=Integer.parseInt(a[i]);
		    sum=sum+array2[i];
		}
		java.util.Arrays.sort(array2);
		System.out.println(array2[n-1]);
		System.out.println(array2[0]);
		System.out.println(sum);
	}
    
}