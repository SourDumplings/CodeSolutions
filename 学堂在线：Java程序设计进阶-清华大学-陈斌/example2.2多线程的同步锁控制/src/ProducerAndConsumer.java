public class ProducerAndConsumer
{
	public static void main(String[] args)
	{
		Tickets t = new Tickets(10); // 建立票对象，票总数10
		
		new Consumer(t).start(); // 开始售票线程
		new Producer(t).start(); // 开始存票线程
		
	}
}


class Tickets
{
	int number = 0; // 已有的最大票号
	int size; // 总票数
	boolean available = false;
	public Tickets(int size)
	{
		this.size = size;
	}
}


class Producer extends Thread
{
	Tickets t = null;
	public Producer(Tickets t)
	{
		this.t = t;
	}
	public void run()
	{
		while (t.number < t.size)
		{
			synchronized(t) // 申请对象的锁
			{
				System.out.println("Producer puts ticket "
							+(++t.number));
				t.available = true;
			} // 释放对象的锁
		}
		System.out.println("Producer ends!");
	}
}


class Consumer extends Thread
{
	Tickets t = null;
	int i = 0; // 将要卖的票号
	public Consumer(Tickets t)
	{
		this.t = t;
	}
	public void run()
	{
		while (i < t.size)
		{
			synchronized(t) // 申请对象t的锁
			{
				if (t.available == true && i <= t.number)
					System.out.println("Consumer buys ticket " +
							(++i));
				if (i == t.number) // 现有的票号买完了
				{
					// 加上休眠代码不会导致死循环，
					try { Thread.sleep(1000); }
					catch (InterruptedException e) {}
					
					t.available = false;
				}
			} // 释放对象t的锁				
		}
	}
}
