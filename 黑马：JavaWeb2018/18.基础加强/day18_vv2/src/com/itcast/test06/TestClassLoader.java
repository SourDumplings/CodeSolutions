package com.itcast.test06;

public class TestClassLoader
{
	public static void main(String[] args)
	{
		// 获取String类的加载器
		ClassLoader classLoader = String.class.getClassLoader();
		// 由于String.class， int.class等字节码文件需要频繁的被加载到内存，速度必须快，底层用其他语言实现如C C++
		// 故而classLoader获取不到
		System.out.println(classLoader);

		// 获取ext（extension）包下的某个类的字节码加载器。ExtClassLoader：扩展类加载器
		ClassLoader classLoader2 = sun.net.spi.nameservice.dns.DNSNameService.class.getClassLoader();
		System.out.println(classLoader2);
		
		// 应用类：程序员实现的所有的类都属于应用类
		// 获取应用类加载器AppClassLoader
		ClassLoader classLoader3 = TestClassLoader.class.getClassLoader();
		System.out.println(classLoader3);
	}
}
