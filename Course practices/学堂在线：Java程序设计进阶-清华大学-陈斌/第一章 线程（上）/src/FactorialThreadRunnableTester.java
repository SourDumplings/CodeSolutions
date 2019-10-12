import java.lang.Thread;

public class FactorialThreadRunnableTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		System.out.println("main thread starts");
		FactorialThreadRunnable thread = 
				new FactorialThreadRunnable(10);
		new Thread(thread).start();
		
		System.out.println("main thread ends");
	}

}


class FactorialThreadRunnable implements Runnable
{
	private int num;
	public FactorialThreadRunnable(int num)
	{
		this.num = num;
	}
	
	public void run()
	{
		int i = num;
		int result = 1;
		System.out.println("new thread started");
		while (i > 0)
		{
			result = result * i;
			i = i - 1;
		}
		System.out.println("The factorial of " +
				num + " is " + result);
		System.out.println("new thread ends");
	}
}

