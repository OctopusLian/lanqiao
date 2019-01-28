import java.io.*;
public class Main
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		double[][] arr = new double[2][4];
		
		String tag1[] = br.readLine().split(" ");
		String tag2[] = br.readLine().split(" ");
		
		for(int b=0;b<4;b++)
		{
			arr[0][b] = Double.valueOf(tag1[b]);
		}
		for(int b=0;b<4;b++)
		{
			arr[1][b] = Double.valueOf(tag2[b]);
		}
		
		double a,b,c,d,e,f,g,h;
		a = Math.max(arr[0][0],arr[0][2]);
		b = Math.min(arr[0][0],arr[0][2]);
		c = Math.max(arr[0][1],arr[0][3]);
		d = Math.min(arr[0][1],arr[0][3]);
		e = Math.max(arr[1][0],arr[1][2]);
		f = Math.min(arr[1][0],arr[1][2]);
		g = Math.max(arr[1][1],arr[1][3]);
		h = Math.min(arr[1][1],arr[1][3]);
		
		if(a<f || e<b || c<h || g<d)
		{
			System.out.println("0.00");
		}
		else
		{
			double i = (Math.min(a,e)-Math.max(b,f));
			double j = (Math.min(c,g)-Math.max(d,h));
			String s = String.format("%.2f",i*j);
			System.out.println(s);
		}
	}
}
