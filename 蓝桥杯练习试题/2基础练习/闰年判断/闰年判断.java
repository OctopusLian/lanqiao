import java.io.*;
import java.util.Scanner;
import java.io.InputStreamReader;
import java.*;

public class Main 
{	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader bf1=new BufferedReader(new InputStreamReader(System.in));
		int num=Integer.parseInt(bf1.readLine());		
			if((num%4==0&&num%100!=0)||(num%400==0))
				System.out.println("yes");
			else
				System.out.println("no");			
	}
}
