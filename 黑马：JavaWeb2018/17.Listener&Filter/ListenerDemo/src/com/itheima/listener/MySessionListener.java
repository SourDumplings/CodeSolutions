package com.itheima.listener;

import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

public class MySessionListener implements HttpSessionListener
{

	public void sessionCreated(HttpSessionEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("创建session了。。。");
	}

	public void sessionDestroyed(HttpSessionEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("销毁session了。。。");
	}

}
