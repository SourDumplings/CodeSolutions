import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.close();
		int g = TwoNum.gcd(n, m);
		System.out.println(g + " " + TwoNum.lcm(n, m, g));
	}

}

class TwoNum
{
	public static int gcd(int n, int m)
	{
		int r = n % m;
		while (r != 0)
		{
			n = m;
			m = r;
			r = n % m;
		}
		return m;
	}

	public static int lcm(int n, int m, int gcd)
	{
		return gcd * (n / gcd) * (m / gcd);
	}
}
