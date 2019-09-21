package com.itheima.spring.demo1;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @ClassName SpringDemo01
 * @Description TODO(测试类)
 * @author SourDumplings
 * @date 2019年9月21日 下午9:57:58
 * 
 * @PL https://github.com/SourDumplings
 */
public class SpringDemo01
{
	/**
	 * @Title demo1
	 * @Description TODO(传统方式的调用)
	 * @param
	 * @return void
	 * @throws
	 */
	@Test
	public void demo1()
	{
		// UserDao userDao = new UserDaoImpl();
		UserDao userDao = new UserDaoHibernateImpl();
		userDao.save();
	}

	/**
	 * @Title demo2
	 * @Description TODO(Spring方式调用)
	 * @param
	 * @return void
	 * @throws
	 */
	@Test
	public void demo2()
	{
		ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
		UserDao userDao = (UserDao) applicationContext.getBean("UserDao");
		userDao.save();
	}
}
