package com.itheima.test;

public class MainTest
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
//		Waiter waiter = new Waitress();
//		waiter.service();
		
		WaitressWrap waitressWrap = new WaitressWrap(new Waitress());
		waitressWrap.service();
	}

}
