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
	int i = 0; // 代售票号
	public Tickets(int size)
	{
		this.size = size;
	}
	public synchronized void put()
	{
		// 同步方法，实现存票功能
		System.out.println("Producer puts ticket " + (++number));
		available = true;
	}
	public synchronized void sell()
	{
		// 同步方法，实现售票功能
		if (available == true && i <= number)
		{
			System.out.println("Consumer buys ticket " + (++i));
		}
		if (i == number)
			available = false;
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
			// 如果存票数小于限定总额则不断存票
			t.put();
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
			// 如果售票数小于限定总量，则不断售票
			t.sell();
		}
	}
}
