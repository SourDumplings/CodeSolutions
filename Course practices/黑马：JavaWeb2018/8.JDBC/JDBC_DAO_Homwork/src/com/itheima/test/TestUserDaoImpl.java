package com.itheima.test;

import java.util.List;

import org.junit.jupiter.api.Test;

import com.itheima.dao.User;
import com.itheima.dao.UserDao;
import com.itheima.dao.impl.UserDaoImpl;

public class TestUserDaoImpl
{
	@Test
	public void testInsert()
	{
		UserDao dao = new UserDaoImpl();
		int lineNum = dao.insert("obama", "911");
		System.out.println("inserting has affected " + lineNum + " lines");
	}
	
	@Test
	public void testDelete()
	{
		UserDao dao = new UserDaoImpl();
		int lineNum = dao.delete(3);
		System.out.println("deleting has affected " + lineNum + " lines");
	}
	
	@Test
	public void testUpdate()
	{
		UserDao dao = new UserDaoImpl();
		int lineNum = dao.update(2, "hell");
		System.out.println("updating has affected " + lineNum + " lines");
	}
	
	
	@Test
	public void testFindAll()
	{
		UserDao dao = new UserDaoImpl();
		List<User> res = dao.findAll();
		
		for (User user : res)
		{
			System.out.println("id: " + user.id + ", username: " +
					user.username + ", password: " + user.password);
		}
	}
	
	@Test
	public void testLogin()
	{
		UserDao dao = new UserDaoImpl();
		User res = dao.login("admin", "10086" );
		if (res != null)
		{
			System.out.println("登录成功！");
			System.out.println("id: " + res.id + ", username: " +
					res.username + ", password: " + res.password);
		}
		else
		{
			System.out.println("登录失败！");
		}
	}
}
