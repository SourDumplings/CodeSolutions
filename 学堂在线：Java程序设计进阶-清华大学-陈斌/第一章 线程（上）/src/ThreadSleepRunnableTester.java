public class ThreadSleepRunnableTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		TestThreadRunnable thread1 = new TestThreadRunnable();
		TestThreadRunnable thread2 = new TestThreadRunnable();
		TestThreadRunnable thread3 = new TestThreadRunnable();
		System.out.println("Starting threads");
		new Thread(thread1, "T1").start();
		new Thread(thread2, "T2").start();
		new Thread(thread3, "T3").start();
		System.out.println("Threads started, main ends");
	}

}


class TestThreadRunnable implements Runnable
{
	private int sleepTime;
	public TestThreadRunnable()
	{
		sleepTime = (int)(Math.random() * 6000); // 休眠0~6s之间
		// Math.random() 产生的是0~1之间的随机数
	}
	public void run()
	{
		try
		{
			System.out.println(Thread.currentThread().getName() + " going to sleep for " +
					sleepTime);
			Thread.sleep(sleepTime); // 线程休眠
		}
		catch (InterruptedException e) {}
		System.out.println(Thread.currentThread().getName() + " finished");
	}
}
