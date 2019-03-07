package com.itheima.listener02;

import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;

public class MyHttpSession02 implements HttpSessionAttributeListener
{

	public void attributeAdded(HttpSessionBindingEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("属性被添加了。。。");
	}

	public void attributeRemoved(HttpSessionBindingEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("属性被移除了。。。");
	}

	public void attributeReplaced(HttpSessionBindingEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("属性被替换了。。。");
	}

}
