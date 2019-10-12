import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		double x, y, z;
		x = sc.nextDouble();
		y = sc.nextDouble();
		z = sc.nextDouble();
		sc.close();
		
		Triangle t = new Triangle(x, y, z);
		System.out.println(t.getArea());
	}

}

class Triangle
{
	private double x, y, z;
	public Triangle(double x, double y, double z)
	{
		double max = -1;
		boolean flag = false;
		if (x > 0 && y > 0 && z > 0)
		{
			if (x + y > z && x + z > y && y + z > x)
			{
				this.x = x;
				this.y = y;
				this.z = z;
				flag = true;
				
			}
			else
			{
				max = x > y ? x : y;
				max = max > z ? max : z;
			}
		}
		else
		{
			max = x > y ? x : y;
			max = max > z ? max : z;
		}
		
		if (max < 0)
			max = 0;
		if (!flag)
			this.x = this.y = this.z = max;
	}
	public double getArea()
	{
		double p = (x + y + z)/2;
		return Math.sqrt(p * (p - x) * (p - y) * (p - z));
	}
}
