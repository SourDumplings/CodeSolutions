import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		int ns = 0, nn = 0;
		String[] s = new String[N];
		Integer[] in = new Integer[N];
		for (int i = 0; i != N; ++i)
		{
			String line = sc.nextLine();
			boolean isNum = true;
			int l = line.length();
			for (int j = 0; j != l; ++j)
			{
				if (!Character.isDigit(line.charAt(j)))
				{
					isNum = false;
					break;
				}
			}
			if (isNum)
			{
				in[nn++] = Integer.parseInt(line);
			}	
			else
			{
				s[ns++] = line;
			}
		}
		(new SortInteger()).doSort(in, nn);
		(new SortString()).doSort(s, ns);
		for (int i = 0; i != nn; ++i)
			System.out.println(in[i]);
		for (int i = 0; i != ns; ++i)
			System.out.println(s[i]);
		sc.close();
	}

}

abstract class Sort<T>
{
	public void doSort(T[] A, int n)
	{
		for (int i = 1; i != n; ++i)
		{
			int j;
			T x = A[i];
			for (j = i; j >= 1 && cmp(x, A[j-1]); --j)
				A[j] = A[j - 1];
			A[j] = x;
		}
	}
	
	public abstract boolean cmp(T a, T b);
	
}

class SortString extends Sort<String>
{
	public boolean cmp(String a, String b)
	{
		return a.compareTo(b) < 0;
	}
}

class SortInteger extends Sort<Integer>
{
	public boolean cmp(Integer a, Integer b)
	{
		return a < b;
	}
}
