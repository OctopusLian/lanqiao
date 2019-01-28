import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int num =Integer.parseInt(bf.readLine());

		String s = bf.readLine();
		int arr [] = sort(s);
		for (int i = 0; i < num; i++) {
			if(Math.abs(arr[i])>10000){
				continue;
			}
			System.out.print(arr[i]+" ");
		}
	}

	private static int [] sort(String s) {
			String [] str = s.split(" ");
			int [] arr = new int[str.length];
			for (int i = 0; i < str.length; i++) {
				arr[i] = Integer.parseInt(str[i]);
			}
			
			for (int i = 0; i < arr.length - 1; i++) {
				for (int j = i+1; j < arr.length; j++) {
					if(arr[i] > arr[j]){
						int temp  = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			return arr;
	}

}