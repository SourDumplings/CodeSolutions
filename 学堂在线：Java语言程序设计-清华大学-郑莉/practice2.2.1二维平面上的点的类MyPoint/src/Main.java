import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		double x1, x2, y1, y2;
		Scanner sc = new Scanner(System.in); 
		x1 = sc.nextDouble();
		y1 = sc.nextDouble();
		x2 = sc.nextDouble();
		y2 = sc.nextDouble();
		sc.close();
		
		MyPoint p1 = new MyPoint(x1, y1), p2 = new MyPoint(x2, y2);
		System.out.println(p1.getD(p2));
	}
}

class MyPoint
{
	private double x, y;
	public MyPoint(double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	public MyPoint()
	{
		this(0, 0);
	}
	public double getD(MyPoint p)
	{
		return Math.sqrt((this.x - p.x) * (this.x - p.x) +
				(this.y - p.y) * (this.y - p.y));
	}
}
