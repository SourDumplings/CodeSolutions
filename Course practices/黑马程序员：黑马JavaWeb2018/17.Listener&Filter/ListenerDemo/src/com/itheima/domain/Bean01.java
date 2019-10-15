package com.itheima.domain;

import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.http.HttpSessionBindingListener;

public class Bean01 implements HttpSessionBindingListener
{
	private String name;

	public String getName()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public void valueBound(HttpSessionBindingEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("对象被绑定进来了。。。。");
	}

	public void valueUnbound(HttpSessionBindingEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("对象被解除绑定了。。。。");
	}
	
}
