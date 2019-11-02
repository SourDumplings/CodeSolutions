package com.cz.hello.spring;

import com.cz.hello.spring.service.UserService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
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
    /*
     * 对于每一个要记录日志的类都要这样创建Logger对象
     * */
    private static final Logger logger = LoggerFactory.getLogger(MyTest.class);

    public static void main(String[] args)
    {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext(
            "spring-context.xml");
        UserService userServiceImpl = (UserService) applicationContext.getBean("userServiceImpl");
        userServiceImpl.sayHi();

        logger.info("info log");
        logger.debug("debug log");
        logger.warn("warn log");
        logger.error("error log");

        String message = "测试";
        String message2 = "测试2";
        /*
        要用这种占位符的方式，不要用+去拼接字符串，会大大影响性能
        * */
        logger.info("message is {} {}", message, message2);

        System.out.println(String.format("message is %s %s", message, message2));
    }
}
