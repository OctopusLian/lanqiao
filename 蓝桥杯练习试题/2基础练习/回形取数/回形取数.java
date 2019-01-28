import java.io.*;
public class Main {
public static void main(String[] args)throws IOException{
   BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
      String s=buf.readLine();
    String str[]=s.split(" ");
    int m=Integer.parseInt(str[0]);
    int n=Integer.parseInt(str[1]);
    int a[][]=new int[m][n];
    int num=m*n;
    int i=0,j=0,x=0,y=0,z=0 ,t=1;
    int p=0;
    for( int g=0;g<m;g++){
    	 String s1=buf.readLine();
    	 String str1[]=s1.split(" ");
    	 for(int f=0;f<n;f++){
    		 int c=Integer.parseInt(str1[f]);
    		a[g][f]=c; 
    	 }
    }
  while(num>0){
	     if(j<n&&x<m){
		p=a[i][j];
		if(i<m-1){
		  i++;
		}
		x++;
		
	     }
	   else  if(j<n-1&&i==m-1){
				  j++;
				  y++;
		      p=a[i][j];
						 //System.out.println(a[i][j]);
	     }
	     else  if(j==y&&i>z){
				  i--;
				  p=a[i][j];
				 // System.out.print(a[i][j]+" ");
	     }
	     else	  if(i==z&&j>z){ 
					  j--;
					  p=a[i][j]; 	
					 // System.out.print(a[i][j]+" .");
				  if(i==z&&j==z+1){
					  z++;
					  i++;
					  m=m-1;
					  n=n-1;
					  x=z;
					  y=z;
					  }
					 
				  }
	     
           num--;
           
	  System.out.print(p+" ");
  }
}
}