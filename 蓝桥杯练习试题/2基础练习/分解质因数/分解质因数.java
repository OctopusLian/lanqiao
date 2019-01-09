import java.io.*;
public class Main{
public static void main(String[] args)throws IOException{
   BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
      String s=buf.readLine();
    String str[]=s.split(" ");
    int i=Integer.parseInt(str[0]);
    int n=Integer.parseInt(str[1]);
    
    for(int j=i;j<=n;j++){
    	StringBuffer b=new StringBuffer();
    	b.append(j).append("=");
    	int x=j;
    	int y=(int)Math.sqrt(x);
    	if(y<2){
    		b.append(j);
    		}
    		else{
    	for(int k=2;k<=y;k++){
    		if(x%k==0){
    			b.append(k).append("*");
    			x=x/k;
    			y=(int)Math.sqrt(x);
    			k=1;
    	
    		}
    			
    	}
    	b.append(x);
    	}
    	System.out.println(b.toString());
    }
    	
    
}
}