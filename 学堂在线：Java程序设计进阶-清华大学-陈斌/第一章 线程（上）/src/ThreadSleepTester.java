import java.lang.Thread;

public class ThreadSleepTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		TestThread thread1 = new TestThread("thread1");
		TestThread thread2 = new TestThread("thread2");
		TestThread thread3 = new TestThread("thread3");
		System.out.println("Starting threads");
		thread1.start();
		thread2.start();
		thread3.start();
		System.out.println("Threads started, main ends");
	}

}


class TestThread extends Thread
{
	private int sleepTime;
	public TestThread(String name)
	{
		super(name);
		sleepTime = (int)(Math.random() * 6000); // 休眠0~6s之间
		// Math.random() 产生的是0~1之间的随机数
	}
	public void run()
	{
		try
		{
			System.out.println(getName() + " going to sleep for " +
					sleepTime);
			Thread.sleep(sleepTime); // 线程休眠
		}
		catch (InterruptedException e) {}
		System.out.println(getName() + " finished");
	}
}
