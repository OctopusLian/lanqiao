import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			int N = sc.nextInt();
			int[] arr = new int[N];
			for (int i = 0; i < N; i++)
				arr[i] = sc.nextInt();
			int count = N;
			for (int i = 0; i < N; i++) {
				int min = arr[i];
				int max = arr[i];
				for (int j = i+1; j < N; j++) {
					if (min > arr[j])
						min = arr[j];
					if (max < arr[j])
						max = arr[j];
					if (max - min == j - i)
						count++;
				}
			}
			System.out.println(count);
		}
	}

}
