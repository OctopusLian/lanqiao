import java.math.BigInteger;
import java.io.*;
import java.util.*;


/**
 * 求一个超长整数的平方根的整数部分
 */
public class Main {

	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		BigInteger n=cin.nextBigInteger();
		BigInteger m=cin.nextBigInteger();
		BigInteger ansn=sqrt(n.toString());
		BigInteger ansm=sqrt(m.toString());
		BigInteger ans=ansn.multiply(ansm);
		System.out.println(ans);
	}
	
	public static BigInteger sqrt(String strNum) {
		BigInteger bigNum = new BigInteger(strNum);
		int bit1 = (strNum.length()-1)/2;
		int bit2 = bit1 + 1;
		
		BigInteger big1 = new BigInteger("10").pow(bit1);
		BigInteger big2 = new BigInteger("10").pow(bit2);
		
		BigInteger result = big1.add(big2).shiftRight(1);
		int comp = result.pow(2).compareTo(bigNum);
		
		while(comp != 0 && big1.add(new BigInteger("1")).compareTo(big2)!=0) {
			if(comp < 0)
				big1 = result;
			else
				big2 = result;
			result = big1.add(big2).shiftRight(1);
			comp = result.pow(2).compareTo(bigNum);
		}
		
		return result;
	}

}