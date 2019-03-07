package com.itheima.listener;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

public class MyServletContextListener implements ServletContextListener
{
	
	// 销毁时调用
	public void contextDestroyed(ServletContextEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("servletContext销毁了");
	}
	
	// 初始化的时候调用
	public void contextInitialized(ServletContextEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("servletContext初始化了");
	}

}
