import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int n,m;
	public static void main(String[] args) throws IOException {
		BufferedReader bfr=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok=new StringTokenizer(bfr.readLine());
//		long begin=System.currentTimeMillis();
		n=Integer.parseInt(tok.nextToken());
		m=Integer.parseInt(tok.nextToken());
		ArrayList<Integer>[] way=new ArrayList[n];
		int count=0;
		int i;
		for(i=0;i<n;i++) way[i]=new ArrayList<Integer>();
		for(i=0;i<m;i++)
		{
			tok=new StringTokenizer(bfr.readLine());
			int x=Integer.parseInt(tok.nextToken())-1, y=Integer.parseInt(tok.nextToken())-1;
			way[x].add(y); way[y].add(x);
		}
		tok=new StringTokenizer(bfr.readLine());
		int g1=Integer.parseInt(tok.nextToken())-1, g2=Integer.parseInt(tok.nextToken())-1;
		
		for(i=0;i<n;i++)
		{
			if(i==g1 || i==g2) continue;
			boolean[] flag=new boolean[n];
			int[] que=new int [n];
			int front=0,rear=1;
			que[0]=g1;
			while(front<rear)
			{
				for(int p=0;p<way[que[front]].size();p++)
				{
					if(way[que[front]].get(p)==i) continue;
					if (!flag[way[que[front]].get(p)])
					{
						que[rear] = way[que[front]].get(p);
						flag[que[rear]]=true;
						if(que[rear]==g2) break;
						rear++;
					}
				}
				if(flag[g2]) { count++; break; }
				front++;
			}
		}
		System.out.println(n-2-count);
//		System.out.println(System.currentTimeMillis()-begin);
	}
}