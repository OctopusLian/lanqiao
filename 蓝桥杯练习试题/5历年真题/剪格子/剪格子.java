import java.util.Scanner;

public class Main{

	
	static int sum,half,m,n;
	static int[][] map;
	static boolean[][] flag;
	static int count=100;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		map=new int[m][n];
		flag=new boolean[m][n];
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				map[i][j]=sc.nextInt();
				sum+=map[i][j];
			}
		
		if(sum%2!=0)
			System.out.println(0);
		else{
			half=sum/2;
			dfs(0,0,1,0);
			System.out.println(count==100?0:count);
		}
		
	}

	private static void dfs(int i, int j, int step,int s) {
		if(i<0 || i>=m || j<0 || j>=n ){
			return;
		}
		if(flag[i][j]==true)
			return;
		if(s>half){
			flag[i][j]=false;
			return;
		}
		
		else{
			s+=map[i][j];
			flag[i][j]=true;
			if(s==half){
				if(step<count)
					count=step;
			}
			else{
				dfs(i+1,j,step+1,s);
				dfs(i,j+1,step+1,s);
				dfs(i-1,j,step+1,s);
				dfs(i,j-1,step+1,s);
				flag[i][j]=false;
			}
				
		}
		
		
	}

}
