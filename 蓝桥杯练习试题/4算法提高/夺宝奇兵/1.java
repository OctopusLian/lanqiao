import java.util.Scanner;
public class Main {
	public static int sum(int[][] bao,int n){
		for (int i = n-2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				int max=bao[i+1][j] > bao[i+1][j+1] ? bao[i+1][j]:bao[i+1][j+1];
				bao[i][j]+=max;
			}
		}
		return bao[0][0];
	}
    public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int[][] bao=new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				bao[i][j]=scan.nextInt();
			}
		}
		System.out.println(sum(bao,n));
	}
}
