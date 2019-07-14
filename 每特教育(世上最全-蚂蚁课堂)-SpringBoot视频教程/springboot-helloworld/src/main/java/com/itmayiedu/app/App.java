package com.itmayiedu.app;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.ComponentScan;

/**
 * @ClassName App
 * @Description TODO(这里用一句话描述这个类的作用)
 * @author SourDumplings
 * @date 2019年7月14日 上午10:38:23
 * 
 * @PL https://github.com/SourDumplings
 */

@ComponentScan(basePackages="com.itmayiedu.controller")
@EnableAutoConfiguration
public class App
{
	public static void main(String[] args)
	{
		SpringApplication.run(App.class, args);
	}
}
