public class Main{

	public static void main(String args[]){
	
		System.out.println("Nine-by-nine Multiplication Table");
		System.out.println("--------------------------------------");	
		System.out.println("1 2 3 4 5 6 7 8 9");	
		System.out.println("--------------------------------------");	
			for(int i=1;i<=9;i++){
				for(int j=1;j<=i;j++){
					if(j<=1){
					System.out.print(i+" "+i*j+" ");
					}
					else{
						System.out.print(i*j+" ");
					}
				}
				System.out.println();
			}System.out.println("--------------------------------------");
}
}
