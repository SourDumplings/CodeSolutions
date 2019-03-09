package com.itcast.test02;

public class UserDao
{
	static
	{
		System.out.println("加载了静态代码段的信息");
	}
	
	@MyTest
	public void addUser()
	{
		System.out.println("增加用户");
	}
	@MyTest
	public void delUser()
	{
		System.out.println("删除用户");
	}
	@MyTest
	public void uptUser()
	{
		System.out.println("更新用户");
	}
	public void getUser()
	{
		System.out.println("获取用户");
	}
}
