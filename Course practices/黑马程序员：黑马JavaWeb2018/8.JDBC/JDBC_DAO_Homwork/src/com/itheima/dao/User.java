package com.itheima.dao;

public class User
{
	public String username;
	public String password;
	public int id;
	
	public User(int id, String username, String password)
	{
		this.id = id;
		this.username = username;
		this.password = password;
	}
}
