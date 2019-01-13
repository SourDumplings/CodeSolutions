import java.lang.Thread;

public class FactorialThreadTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		System.out.println("main thread starts");
		FactorialThread thread = new FactorialThread(10);
		thread.start();
		
//		// 线程休眠1ms
//		try { Thread.sleep(1); }
//		catch (Exception e) {}
		
		System.out.println("main thread ends");
	}

}


class FactorialThread extends Thread
{
	private int num;
	public FactorialThread(int num)
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
