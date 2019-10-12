import java.util.concurrent.locks.ReentrantLock;;

public class BufferedInterruptibly
{
	private ReentrantLock lock = new ReentrantLock();
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		
	}
	
	public void write()
	{
		lock.lock();
		try
		{
			long startTime = System.currentTimeMillis();
			System.out.println("开始往这个buff写入数据...");
			for (;;)
			{
				if (System.currentTimeMillis() - startTime > Integer.MAX_VALUE)
				{
					break;
				}
			}
		}
		finally
		{
			lock.unlock();
		}
	}
	
	public void read() throws InterruptedException
	{
		lock.lockInterruptibly();
		try
		{
			System.out.println("从这个buff读数据");
		}
		finally
		{
			lock.unlock();
		}
	}

}
