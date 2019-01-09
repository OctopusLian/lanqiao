import java.util.*;

//2n皇后问题

public class Main {
	public static final int no=0; 
	public static final int yes=1; 
	public static final int hei=2; 
	public static final int bai=3;
	public static int n;
	public static int[][] qipan=null;
	public static int count=0;
	public static int num=0; 
	

	public static int get(int qizi){
	  int num=qizi==2? 3: 2;
	  return num;
	}

	public static boolean jc(int k,int m,int qizi){
		if(qipan[k][m]==get(qizi)||qipan[k][m]==no){ 
			return false;
		}
		
        for(int i=0;i<n;i++){ 
            if(qipan[i][m]==qizi){       
                  return false;            
            }         
        }
        
        int i=0,j=0;  
        for(i=k,j=m;i<n&&j<n;i++,j++){    
             if(qipan[i][j]==qizi){              
                 return false;           
             }        
        }        
        for(i=k,j=m;i>=0&&j>=0;i--,j--){   
           if(qipan[i][j]==qizi){     
                 return false;      
           }      
        }       
        for(i=k,j=m;i>=0&&j<n;i--,j++){ 
             if(qipan[i][j]==qizi){  
                return false;    
             }       
        }         
        for(i=k,j=m;i<n&&j>=0;i++,j--){   
             if(qipan[i][j]==qizi){ 
                 return false;  
             }       
        }       
		
		return true;
	}

	public static boolean sum(){
		int bainum=0;
		int heinum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(qipan[i][j]==bai)
					bainum++;
				if(qipan[i][j]==hei)
					heinum++;
			}
		}
		if(bainum==n&&heinum==n){
			num++;
			return true;
		}
		return false;
			
	}
	
	public static void mk(int line , int qizi){
		if(line>=n) return ; 
		for(int i=0;i<n;i++){
			if(jc(line,i,qizi)){
				qipan[line][i]=qizi;
				count++;
				if(count>=n){
					if(sum()){
					}
					int c=count;
					count=0;
					mk(0,bai); 
					count=c;
				}
				mk(line+1,qizi);
				qipan[line][i]=yes; 
				count--; 
			}
			
		}
	}
	
	public static void print(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				System.out.print(qipan[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println(":"+num);
	}
	
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		n=scan.nextInt();
		qipan=new int[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				qipan[i][j]=scan.nextInt();
			}
		}
		mk(0,hei);
		
		System.out.println(num);
	}
}