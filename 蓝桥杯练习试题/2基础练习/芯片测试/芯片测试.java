import java.io.*;
public class Main {
	public static void main(String[] args)throws Exception {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(bf.readLine());	
		int a[][]=new int[n][n];
		int b[]=new int[n*n];
		int i=0,j=0;
		
		for(i=0;i<n;i++){
			String s[]=bf.readLine().split(" ");
		for(j=0;j<n;j++){
			a[i][j]=Integer.parseInt(s[j]);
			if(a[i][j]==0)
				b[j]=b[j]+1;
	}
	}
		for(i=0;i<n;i++)
			
			if(b[i]<=n/2)
				System.out.print(i+1+" ");
		
}
}
