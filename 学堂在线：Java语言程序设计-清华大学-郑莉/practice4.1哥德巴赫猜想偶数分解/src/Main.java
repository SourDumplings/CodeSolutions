import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		sc.close();

		Prime p = new Prime(n);
		for (int firstNum = p.nextPrime(); firstNum != -1 && firstNum <= n / 2; firstNum = p.nextPrime())
		{
			if (p.isPrime(n - firstNum))
				System.out.println(n + "=" + firstNum + "+" + (n - firstNum));
		}
	}

}

class Prime
{
	boolean[] PrimeNum;
	int thisNum, upperLimit;
	public Prime(int n)
	{
		upperLimit = n;
		PrimeNum = new boolean[n];
		for (int i = 0; i != n; ++i)
			PrimeNum[i] = true;
		for (int i = 2; i != n; ++i)
		{
			if (PrimeNum[i])
			{
				for (int j = 2 * i; j < n; j += i)
					PrimeNum[j] = false;
			}
		}
		thisNum = 0;
	}
	public boolean isPrime(int num)
	{ return PrimeNum[num]; }
	public int nextPrime()
	{
		if (thisNum == 2)
		{
			thisNum = 3;
		}
		else if (thisNum == 0)
		{
			thisNum = 2;
		}
		else
		{
			for (thisNum = thisNum + 2; thisNum < upperLimit; thisNum += 2)
			{
				if (PrimeNum[thisNum])
				{
					break;
				}
			}
		}
		if (thisNum >= upperLimit)
			return -1;
		else
			return thisNum;
	}
}
