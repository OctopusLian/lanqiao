import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bfr=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok= new StringTokenizer(bfr.readLine());
		int i=0,j,flag=1;
		int[] monk=new int[108];
		while(tok.hasMoreTokens()) monk[i++]=Integer.parseInt(tok.nextToken());
		int N=i-1;
		int[] A=new int[N];
		for(i=0;i<N;i++) A[i]=monk[i+1]-monk[i]-1;
		
		int sum=A[0];
		for(i=2;i<N;i++,i++) sum^=A[i];
		
		if(sum==0) System.out.println(-1);
		else
		{
			for(i=0;i<N;i++)
			{
				for(j=1;j<=A[i];j++)
				{
					int s=sum;
					A[i]-=j;
					if(i>0) A[i-1]+=j;
					if(i%2==0)  { s^=(A[i]+j); s^=A[i]; }
					else { s^=(A[i-1]-j); s^=A[i-1]; }
					if(s==0) { System.out.println(monk[i]+" "+(monk[i]+j)); flag=0; break; }
					else { A[i]+=j; if(i>0) A[i-1]-=j; }
				}
				if(flag==0) break;
			}
		}
	}
}