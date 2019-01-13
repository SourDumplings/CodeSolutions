import java.lang.Thread;

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
			System.out.println("Producer puts ticket "
						+(++t.number));
			t.available = true;
		}
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
			if (t.available == true && i <= t.number)
				System.out.println("Consumer buys ticket " +
						(++i));
			if (i == t.number) // 现有的票号买完了
			{
//				// 加上休眠代码会导致死循环，
//				// 即Consumer运行到此处时存票线程运行，把票存完了
//				// 这时候Consumer把t.available设置为了false，
//				// 但由于存票线程已经运行完，便无法将t.available再设置为true了
//				try { Thread.sleep(10); }
//				catch (InterruptedException e) {}
				
				t.available = false;
			}
				
		}
	}
}
