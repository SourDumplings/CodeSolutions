package com.itcast.test02;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class MyJunit
{
	public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, IllegalArgumentException, InvocationTargetException
	{
		// 加载UserDao.class字节码文件中的方法，判断哪些方法中有注解@MyTest,
		// 有该注解的方法执行，否则不执行
		
		// 1.将UserDao.class字节码文件加载到内存，形成class对象（代表字节码文件在内存中的对象）
		Class clazz = Class.forName("com.itcast.test02.UserDao");
		
		// 2.获取字节码对象上所有的方法，返回数组对象，数组中每个元素都代表一个Method对象（相当于UserDao字节码上的每一个方法）
		Method[] mds = clazz.getMethods();
		
		// 3.遍历字节码对象上所有的方法
		for (Method method : mds)
		{
			// 测试方法的名称
			System.out.println(method.getName());
			
			// 判断当前方法上是否有@MyTest注解的信息
			System.out.println(method.isAnnotationPresent(MyTest.class));
			if (method.isAnnotationPresent(MyTest.class))
			{
				// 如果当前的方法上有@MyTest注解，执行，否则忽略
				method.invoke(new UserDao());
			}
		}
	}
}
