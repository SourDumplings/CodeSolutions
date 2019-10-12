package com.itcast.test01;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

/**   
 * @ClassName  TestAnnotation   
 * @Description TODO(这里用一句话描述这个类的作用)   
 * @author SourDumplings
 * @date   2019年3月8日 下午3:19:04   
 *     
 * @PL https://github.com/SourDumplings
 */ 
public class TestAnnotation
{
	// 以下注解的含义是：声明当前的方法是重写父类的方法
	@Override
	public String toString()
	{
		// TODO Auto-generated method stub
		return super.toString();
	}
	
	// junit单元测试的注解
	@Test
	public void test01()
	{
		// 以下注解的含义：抵制编译器警告：告诉编译器，不要报警没用过的变量
		@SuppressWarnings("unused")
		int i;
		// 以下注解的含义：抵制编译器警告：告诉编译器，不要报警没用过的变量，不要警告没有加泛型的类型
		@SuppressWarnings({ "rawtypes", "unused" })
		List a = new ArrayList();
	}
	
	// 以下注解的含义是：声明以下的方法是过时的方法，不建议使用
	@Deprecated
	public void test02()
	{
		
	}
	
	// 以下注解的含义是：若该方法在1s内没有结束则抛出异常
	@Test(timeout=1000)
	public void test03()
	{
		try
		{
			Thread.sleep(1500);
		}
		catch (InterruptedException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("123");
	}
}
