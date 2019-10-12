package com.itheima.test;

import org.junit.jupiter.api.Test;

import com.itheima.dao.UserDao;
import com.itheima.dao.impl.UserDaoImpl;

public class TestUserDaoImpl
{
	@Test
	public void testInsert()
	{
		UserDao dao = new UserDaoImpl();
		dao.insert("obama", "911");
	}
	
	@Test
	public void testDelete()
	{
		UserDao dao = new UserDaoImpl();
		dao.delete(40);
	}
	
	@Test
	public void testUpdate()
	{
		UserDao dao = new UserDaoImpl();
		dao.update(2, "hello");
	}
	
	
	@Test
	public void testFindAll()
	{
		UserDao dao = new UserDaoImpl();
		dao.findAll();
		
	}
	
	@Test
	public void testLogin()
	{
		UserDao dao = new UserDaoImpl();
//		dao.login("admin", "10088");
//		dao.login("admin", "10086");
		
		// Statement漏洞，这样也能登录成功，要用PrepareStatement
//		SELECT * FROM t_user WHERE username='admin' AND PASSWORD='100234khsdf88' or '1=1' 
		dao.login("admin", "100234khsdf88' or '1 = 1" );
	}
}
