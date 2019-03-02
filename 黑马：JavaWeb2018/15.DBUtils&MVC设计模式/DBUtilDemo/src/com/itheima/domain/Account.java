package com.itheima.domain;

public class Account
{
	private String name;
	private int money;
	public String getName()
	{
		return name;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public int getMoney()
	{
		return money;
	}
	public void setMoney(int money)
	{
		this.money = money;
	}
	@Override
	public String toString()
	{
		return "Account [name=" + name + ", money=" + money + "]";
	}
	
	
}
