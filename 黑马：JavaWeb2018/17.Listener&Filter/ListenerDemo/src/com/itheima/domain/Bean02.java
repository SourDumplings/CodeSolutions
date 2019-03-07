package com.itheima.domain;

import java.io.Serializable;

import javax.servlet.http.HttpSessionActivationListener;
import javax.servlet.http.HttpSessionEvent;

public class Bean02 implements HttpSessionActivationListener, Serializable
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

	public void sessionDidActivate(HttpSessionEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("session中的值被活化了。。。");
	}

	public void sessionWillPassivate(HttpSessionEvent arg0)
	{
		// TODO Auto-generated method stub
		System.out.println("session中的值被钝化了。。。");
	}

}
