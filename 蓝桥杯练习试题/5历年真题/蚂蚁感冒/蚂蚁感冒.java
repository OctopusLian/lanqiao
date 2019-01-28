import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n+1];
		int b[]=new int[n+1];
		for(int i=1;i<=n;i++){
			a[i]=sc.nextInt();
			if(a[i]<0)
				b[i]=0;
			else {
				b[i]=1;
			}
		}
		 int k=a[1]>0?1:0;
		 int x=0,y=0,q=0,w=0;
		for(int i=2;i<=n;i++){
			if(Math.abs(a[1])<Math.abs(a[i])&&a[1]>0&&b[i]==0)
				x++;
			if(Math.abs(a[1])>Math.abs(a[i])&&a[1]<0&&b[i]==1)
				y++;
			if(Math.abs(a[1])>Math.abs(a[i])&&a[1]>0&&b[i]==1)
				q++;
			if(Math.abs(a[1])<Math.abs(a[i])&&a[1]<0&&b[i]==0)
				w++;
		}
		if(k==1)
			if(x!=0)
			System.out.println(x+q+1);
			else
				System.out.println(1);
		else {
			if(y!=0)
			System.out.println(y+w+1);
			else {
				System.out.println(1);
			}
		}
		
	}

}
