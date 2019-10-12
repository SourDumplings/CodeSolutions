import java.lang.Thread;

// 3个线程模拟3个售票窗口
// 3个线程共享200张票

public class SellTicketsTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		SellTickets t = new SellTickets();
		new Thread(t).start();
		new Thread(t).start();
		new Thread(t).start();
	}

}


class SellTickets implements Runnable
{
	private int tickets = 200;
	public void run()
	{
		while (tickets > 0)
		{
			System.out.println(Thread.currentThread().getName() +
					" is selling tickets " + tickets--);
		}
	}
}
