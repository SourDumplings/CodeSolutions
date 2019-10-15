package com.itheima.test;

public class WaitressWrap implements Waiter
{
	Waitress waiter = null;
	
	public WaitressWrap(Waiter waiter)
	{
		// TODO Auto-generated constructor stub
		this.waiter = (Waitress) waiter;
	}
	
	
	@Override
	public void service()
	{
		// TODO Auto-generated method stub
		System.out.println("微笑");
		waiter.service();
		
	}
	
}
