package com.cz.hello.spring.boot.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-boot
 * @date 2019/11/21 9:34
 */
@RestController
public class HelloController
{
    @RequestMapping(value = "hello")
    public String sayHi()
    {
        return "Hello Spring Boot";
    }
}
