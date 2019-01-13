import java.lang.Thread;

public class ShareTargetTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		TestSharedThread threadobj = new TestSharedThread();
		System.out.println("Starting threads");
		
		new Thread(threadobj, "Thread1").start();
		new Thread(threadobj, "Thread2").start();
		new Thread(threadobj, "Thread3").start();
		
		System.out.println("Threads started, main ends\n");
	}

}


class TestSharedThread implements Runnable
{
	private int sleepTime;
	public TestSharedThread()
	{
		sleepTime = (int)(Math.random() * 6000);
	}
	public void run()
	{
		try
		{
			System.out.println(Thread.currentThread().getName() +
						" going to sleep for " + sleepTime);
			Thread.sleep(sleepTime);
		}
		catch (InterruptedException e) {}
		System.out.println(Thread.currentThread().getName() + " finished");
	}
}
