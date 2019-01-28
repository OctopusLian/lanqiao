import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.ArrayList;

public class Main
{
	private static BufferedInputStream in = new BufferedInputStream(System.in);
	private static ArrayList<Node> n = new ArrayList<Node>();
	private static Integer dis = 0;
	private static Integer pow = 0;
	
	public static void main(String[] args) throws IOException
	{
		int size = readInt();
		
		for(int i=0; i<size; i++)
		{
			n.add(null);
		}
		
		for(int i=1; i<size; i++)
		{
			int x = readInt()-1;
			int y = readInt()-1;
			int d = readInt();
			
			Node node = new Node();
			node.nextSide = n.get(x);
			node.con = y;
			node.power = d;
			n.set(x, node);
			
			node = new Node();
			node.nextSide = n.get(y);
			node.con = x;
			node.power = d;
			n.set(y, node);
		}
		
		away(0, 0, -1);
		pow = 0;
		away(dis, 0, -1);
		System.out.println(pow * 10 + (1 + pow) * pow /2);
	}
	
	private static void away(int index, int power, int from)
	{
		if(pow < power)
		{
			pow = power;
			dis = index;
		}
		
		Node node = n.get(index);
		
		while(node != null)
		{
			if(node.con == from)
			{
				node = node.nextSide;
				continue;
			}
			
			away(node.con, power + node.power, index);
			
			node = node.nextSide;
		}
	}
	
	private static int readInt() throws IOException
	{
		int i,sum=0;
		
		while(((i=in.read())&48) != 48 || i>57);
		
		for(;(i&56) == 48 || (i&62) == 56; i=in.read())
			sum = sum*10 + (i&15);
		
		return sum;
	}
	
	private static class Node
	{
		int power;
		int con;
		Node nextSide;
	}
}
