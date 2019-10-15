package com.itheima.listener;

import javax.servlet.ServletRequestEvent;
import javax.servlet.ServletRequestListener;

public class MyRequestListener implements ServletRequestListener
{

	public void requestDestroyed(ServletRequestEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("servletRequest销毁了");
	}

	public void requestInitialized(ServletRequestEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("servletRequest初始化了");
	}

}
