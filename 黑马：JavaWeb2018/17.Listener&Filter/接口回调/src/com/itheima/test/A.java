package com.itheima.test;

public class A
{
	/**   
	 * 这是以前的Java基础的代码。
	 * 但是假设这个A这个类是古老的代码，不知道B的存在，不能new B 也不能传B的实例
	 * 解决方法是传接口，未来的实例也能用，见项目接口回调02
	 *	
	 */  
	public void print()
	{
		for (int i = 0; i < 10; i++)
		{
			System.out.println("循环到了：i = " + i);
			if (i == 5)
			{
				System.out.println("循环到了5了，该通知B了");
				B b = new B();
				b.printFive();
			}
		}
	}
}
