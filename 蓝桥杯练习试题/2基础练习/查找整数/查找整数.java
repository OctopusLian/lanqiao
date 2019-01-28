import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.InputStreamReader;

public class Main 
{
	
	static int fun(int[] num,int nn)
	{
		for(int i=0;i<num.length;i++)
		{
			if(num[i]==nn)
				return i+1;				
		}
		return -1;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader bf1=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(bf1.readLine());
		String[] s1=bf1.readLine().split(" ");
		int[] num=new int[n];
		for(int i=0;i<n;i++)
			num[i]=Integer.parseInt(s1[i]);
		int nn=Integer.parseInt(bf1.readLine());
		System.out.println(fun(num, nn));
			
	}

}
