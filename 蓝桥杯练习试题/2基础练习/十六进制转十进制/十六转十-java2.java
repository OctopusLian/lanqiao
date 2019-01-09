import java.io.*;
public class Main {
public static void main (String args[])throws Exception{
	BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
	String s=buf.readLine();
	char c[]=s.toCharArray();
   int n=c.length;
   long sum=0;
   for(int i=0;i<n;i++){
	   
	   if((int)c[i]-48>9){
		   if(c[i]=='A')
			  sum+=10*Math.pow(16,n-i-1);
		   else if(c[i]=='B')
			   sum+=11*Math.pow(16,n-i-1);
		   else if(c[i]=='C')
			   sum+=12*Math.pow(16,n-i-1);
		   else if(c[i]=='D')
			   sum+=13*Math.pow(16,n-i-1);
		   else if(c[i]=='E')
			   sum+=14*Math.pow(16,n-i-1);
		   else if(c[i]=='F')
			  sum+=15*Math.pow(16,n-i-1);
	   }
	   else{
		  sum+=((int)c[i]-48)*Math.pow(16,n-i-1);
	   }
   }
   
    System.out.println(sum);
}
}