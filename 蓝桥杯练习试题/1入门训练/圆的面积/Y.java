import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
	        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	        BigDecimal  bg = new BigDecimal(bf.readLine());
	        BigDecimal value = bg.multiply(bg.multiply(new BigDecimal(Math.PI))).setScale(7,BigDecimal.ROUND_HALF_UP);
	        System.out.println(value);
	}
}