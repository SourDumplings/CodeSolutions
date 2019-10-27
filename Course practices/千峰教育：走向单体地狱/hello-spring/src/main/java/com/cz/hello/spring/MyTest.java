package com.cz.hello.spring;

import com.cz.hello.spring.service.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 千峰教育：走向单体地狱
 * @date 2019/10/27 16:45
 */
public class MyTest
{
    public static void main(String[] args)
    {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-context.xml");
        UserService userServiceImpl = (UserService) applicationContext.getBean("UserServiceImpl");
        userServiceImpl.sayHi();
    }
}
