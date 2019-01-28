import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;          

public class Main{
	public static void main(String args[]) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    int n=Integer.parseInt(br.readLine());
	    int[][] a=new int[34][34];
	    int i=0,j=1;
	    while(i<34){
	    	a[i][0]=1;
	    	i++;
	    }
	    while(j<34){
	    	a[j][j]=1;
	    	j++;
	    }
	    for(i=2;i<34;i++)
	       for(j=1;j<i;j++)
	          a[i][j]=a[i-1][j-1]+a[i-1][j];
	    for(i=0;i<n;i++)
	       {for(j=0;j<=i;j++)
	         System.out.print(a[i][j]+" ");
	       System.out.println(" ");}
}
}	               
