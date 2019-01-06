//各位小伙伴最容易出错的地方就是在计算S的值得时候，除的是2，不是2.0，必须是2.0，不然会丢失精度，丢失了精度只能得10分

import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		for (int i = 0; i != N; ++i)
		{
			String[] sData = sc.nextLine().trim().split(" ");
			if (sData.length == 2)
			{
				System.out.println((new Rectangle(sData)).getArea());
			}
			else
			{
				System.out.println((new Triangle(sData)).getArea());
			}
		}
		sc.close();
	}
}

abstract class Graph
{
	public String[] sData;
	Graph(String[] sData)
	{
		this.sData = sData;
	}
	public abstract int getArea();
}

class Rectangle extends Graph
{
	Rectangle(String[] sData)
	{
		super(sData);
	}
	public int getArea()
	{
		int a = Integer.parseInt(sData[0]);
		int b = Integer.parseInt(sData[1]);
		return a * b;
	}
}

class Triangle extends Graph
{
	Triangle(String[] sData)
	{
		super(sData);
	}
	public int getArea()
	{
		int a = Integer.parseInt(sData[0]);
		int b = Integer.parseInt(sData[1]);
		int c = Integer.parseInt(sData[2]);
		double p = (a + b + c) / 2.0;
		return (int)Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}
}
