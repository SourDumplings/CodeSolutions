package com.itcast.test02;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;


// 自定义注解，相当于JUit@Test
// 定义注解时，必须说明该注解是运行时有效，否则反射获取不到，需要使用元注解说明当前自定义注解的作用域
@Retention(RetentionPolicy.RUNTIME)
// 定义注解时，使用元注解Target说明当前的自定义注解的目标对象是方法
@Target(ElementType.METHOD)
public @interface MyTest
{
	// 在MyTest注解中定义一个成员属性，默认-1
	public long timeout() default -1;
}
