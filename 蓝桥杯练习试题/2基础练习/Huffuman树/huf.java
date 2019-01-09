import java.io.*;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args)throws IOException {
	BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
	int n=Integer.parseInt(buf.readLine());
	String str=buf.readLine();
	String s[]=str.split(" ");
     int sum=0;
     int a[] =new int[n];
     int num=0;
  for(int i=0;i<n;i++)
    	 a[i]=Integer.parseInt(s[i]);
    	  java.util.Arrays.sort(a);
    	  
    	  if(n>1){
    	  sum=a[0]+a[1];
    	  num=sum;
    	  a[1]=num;
    	  for(int j=2;j<n;j++){
    		  if(j<n){
    			  java.util.Arrays.sort(a);
    			  num=a[j-1]+a[j];
    		     a[j]=num;
    		 java.util.Arrays.sort(a);
    		 sum+=num;
    		  }
    		  
    	  }
    	  }
    	  else {
    	     
    		 sum=a[0];
    	  }
    	System.out.println(sum);

	}

}