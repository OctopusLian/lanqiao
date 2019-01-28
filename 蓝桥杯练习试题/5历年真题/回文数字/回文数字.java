import java.util.*;
public class Main {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int sum=sc.nextInt();
		List list=new ArrayList();
		double fsum=sum/2.0;
		for(int i=1;i<=9;i++)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
				{
					if(i+j+k/2.0==fsum)
						list.add(i*10000+j*1000+k*100+j*10+i);
					if(i+j+k+0.0==fsum)
						list.add(i*100000+j*10000+k*1000+k*100+j*10+i);
				}
	
		Collections.sort(list);
		if(list.size()==0) {System.out.println("-1");return;}
		for(int i=0;i<=list.size()-1;i++)
			System.out.println(list.get(i));
	}

}
