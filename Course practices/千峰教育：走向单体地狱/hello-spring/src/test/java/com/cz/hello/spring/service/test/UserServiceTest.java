package com.cz.hello.spring.service.test;

import static junit.framework.TestCase.assertNotNull;
import static junit.framework.TestCase.assertTrue;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertSame;


import com.cz.hello.spring.service.UserService;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 千峰教育：走向单体地狱
 * @date 2019/10/29 9:28
 */
public class UserServiceTest
{
    private UserService userService;

    @Before
    public void before()
    {
        System.out.println("初始化数据库连接");
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext(
            "spring-context.xml");
        userService = (UserService) applicationContext.getBean("UserServiceImpl");
    }

    @Test
    public void testSayHi()
    {
        userService.sayHi();
    }

    @Test
    public void testSayHello()
    {
        System.out.println("Hello JUnit");
    }

    @After
    public void after()
    {
        System.out.println("关闭数据库连接");
    }

    /**
     * 测试断言，断言用的是静态方法
     */
    @Test
    public void testAssert()
    {
        String obj1 = "junit";
        String obj2 = "junit";
        String obj3 = "test";
        String obj4 = "test";
        String obj5 = null;
        int var1 = 1;
        int var2 = 2;
        int[] arithmetic1 = {1, 2, 3};
        int[] arithmetic2 = {1, 2, 3};

        // true
        assertEquals(obj1, obj2);

        // true
        assertSame(obj3, obj4);

        assertNotSame(obj2, obj4);

        assertNotNull(obj1);

        assertNull(obj5);

        // false
//        assertTrue("为真", var1 == var2);

        assertArrayEquals(arithmetic1, arithmetic2);
    }
}
