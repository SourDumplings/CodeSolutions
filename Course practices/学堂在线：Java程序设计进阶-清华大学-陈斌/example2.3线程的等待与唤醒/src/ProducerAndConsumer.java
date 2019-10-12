// 每次存入一张票，就售一张票，售出后，再存入

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
		if (available) // 有存票待售就等待
			try { wait(); } catch (Exception e) {}
		
		System.out.println("Producer puts ticket " + (++number));
		available = true;
		notify(); // 存票后唤醒售票线程开始售票
	}
	public synchronized void sell()
	{
		// 同步方法，实现售票功能
		if (!available) // 没有存票则售票线程等待
			try { wait(); } catch (Exception e) {}
		
		System.out.println("Consumer buys ticket " + (++i));
		available = false;
		notify(); // 售票后唤醒存票线程开始存票
		if (number == size)
			number = size + 1; // 在售完最后一张票后
		// number > size时售票结束
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
	public Consumer(Tickets t)
	{
		this.t = t;
	}
	public void run()
	{
		while (t.number <= t.size)
		{
			// 如果存票数小于等于限定总量，则不断售票
			// 因为是存一张卖一张，所以可以这样来
			t.sell();
		}
	}
}
