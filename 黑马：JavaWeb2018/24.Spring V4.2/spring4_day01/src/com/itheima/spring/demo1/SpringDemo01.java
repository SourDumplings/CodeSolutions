package com.itheima.spring.demo1;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

/**
 * (测试类)
 *
 * @author SourDumplings
 * @ClassName SpringDemo01
 * @Description TODO
 * @date 2019年9月21日 下午9:57:58
 * @PL https://github.com/SourDumplings
 */
public class SpringDemo01
{
    /**
     * (传统方式的调用)
     *
     * @param
     * @return void
     * @throws
     * @Title demo1
     * @Description TODO
     */
    @Test
    public void demo1()
    {
        // UserDao userDao = new UserDaoImpl();
        UserDao userDao = new UserDaoHibernateImpl();
        userDao.save();

        UserDaoImpl userDaoImpl = new UserDaoImpl();
        userDaoImpl.setName("zhangsan");
    }

    /**
     * (Spring方式调用)
     *
     * @param
     * @return void
     * @throws
     * @Title demo2
     * @Description TODO
     */
    @Test
    public void demo2()
    {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserDao userDao = (UserDao) applicationContext.getBean("UserDao");
        userDao.save();
    }

    /**
     * 加载磁盘上的配置文件
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/6 22:41
     */
    @Test
    public void demo3()
    {
		ApplicationContext applicationContext = new FileSystemXmlApplicationContext("C:\\Users\\sourd\\Downloads\\applicationContext.xml");
		UserDao userDao = (UserDao) applicationContext.getBean("UserDao");
		userDao.save();
    }
}
