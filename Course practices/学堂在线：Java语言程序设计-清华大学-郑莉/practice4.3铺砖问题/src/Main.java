import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.close();

		Solve s = new Solve(N);
		System.out.println(s.getSolution(N));

	}

}

class Solve
{
	public long[] A;
	public Solve(int N)
	{
		N = N > 2 ? N : 2;
		A = new long[N + 1];
		for (int i = 0; i != N + 1; ++i)
			A[i] = -1;
		A[0] = 0;
		A[1] = 1;
		A[2] = 2;
	} 
	long getSolution(int N)
	{
		if (A[N] == -1)
		{
			A[N] = getSolution(N - 1) + getSolution(N - 2);
		}
		return A[N];
	}
}

