package cn.itcast.servlet;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class TestAA
{
	public static void main(String[] args) throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException
	{
		// 获取到AA字节码在内存中的对象
		Class clazz = AA.class;
		
		// 获取AA字节码对象上名称为sum的方法，方法有2个参数
		Method md = clazz.getMethod("sum", int.class, int.class);
		
		// 执行md这个方法
		md.invoke(new AA(), 123, 4);
	}
}
