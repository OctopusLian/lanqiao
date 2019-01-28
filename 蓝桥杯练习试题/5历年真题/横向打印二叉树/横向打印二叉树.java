import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	 static int n;
	    static int[] a=new int[108];
	    static int[] left;
	    static int[] right;
	    static int[] level;
	    static int maxl=0;
	    static int M,N;
	    static char[][] map;
	    static boolean[] flag;
	    static boolean[] flag2;
	    
	    static void add(int root,int index)
	    {
	        if(a[index]<a[root])
	            if(left[root]==0) { left[root]=index; level[index]=level[root]+1; if(level[index]>maxl) maxl=level[index]; }
	            else add(left[root],index);
	        else
	            if(right[root]==0) { right[root]=index; level[index]=level[root]+1; if(level[index]>maxl) maxl=level[index]; }
	            else add(right[root],index);
	    }
	    
	    static void Fill(int root,int x,int y)
	    {
	        int lvl=level[root]+1;
	        String num=String.valueOf(a[root]);
	        int len=num.length();
	        flag[x]=true;
	        for(int i=0;i<len;i++)
	        {
	            map[x][y-i]=num.charAt(i);
	            int h=2<<(maxl-lvl);
	            for(int j=1;j<h;j++) { map[x+j][y-i]='.'; map[x-j][y-i]='.'; }
	        }
	        if(left[root]==0 && right[root]==0 && level[root]<maxl) flag2[x]=true;
	        if(left[root]!=0)
	            Fill(left[root],x+(2<<(maxl-lvl))/2,y-8);
	        if(right[root]!=0)
	            Fill(right[root],x-(2<<(maxl-lvl))/2,y-8);
	    }
	    
	    public static void main(String[] args) throws IOException {
	        BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
	        StringTokenizer tok=new StringTokenizer(bfr.readLine());
//	      long begin=System.currentTimeMillis();
	        int i,j;
	        for(i=1;tok.hasMoreTokens();i++) a[i]=Integer.parseInt(tok.nextToken());
	        n=i;
	        left =new int[n];
	        right =new int[n];
	        level=new int[n];
	        left[0]=1; right[0]=1; level[0]=0; level[1]=1;
	        for(i=2;i<n;i++)
	            add(1,i);
	        M=(2<<(maxl-1))-1;
	        N=8*maxl-3;
	        map=new char[M][N];
	        flag=new boolean[M];
	        flag2=new boolean[M];
	        for(int l=1;l<maxl;l++)
	        {
	            int ty=l*8-1;
	            int start=(2<<(l-1))-1,d=(2<<l);
	            for(i=0;i<M;i++) map[i][ty]=map[i][ty-1]=map[i][ty-2]='.'; 
	            for(i=start;i<M;i+=d)
	            {
	                map[i][ty]='-';
	                int hei=(2<<(l-1))/2;
	                for(int ii=0;ii<=hei;ii++)
	                {
	                    map[i+ii][ty-1]='|';
	                    map[i-ii][ty-1]='|';
	                }
	                map[i+hei][ty-2]='-';
	                map[i-hei][ty-2]='-';
	            }
	        }
	        Fill(1,M/2,N-1);
	        
	        for(i=0;i<M;i++)
	        {
	            if(flag[i])
	            {
	                for(j=0;;j++) if(map[i][j]!=0 && map[i][j]!='.') break;
	                int jj;
	                for(jj=N-1;jj>j+1;jj--) if(map[i][jj]!=0) System.out.print(map[i][jj]);
	                if(!flag2[i]) System.out.print(map[i][jj]+""+map[i][jj-1]);
	                System.out.println();
	            }
	        }
//	      System.out.println(System.currentTimeMillis()-begin);
	    }
	}