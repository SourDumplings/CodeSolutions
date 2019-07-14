package com.itmayiedu.controller;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @ClassName TestController
 * @Description TODO(这是我们第一个SpringBoot)
 * @author SourDumplings
 * @date 2019年7月13日 下午11:02:45
 * 
 * @PL https://github.com/SourDumplings
 */
@RestController
//@EnableAutoConfiguration
public class TestController2
{
	@RequestMapping("/hello2")
	public String hello()
	{
		return "hello2";
	}
	
	
//	public static void main(String[] args)
//	{
//		// 开始运行
//		SpringApplication.run(TestController2.class, args);
//	}
}
