package com.itheima.test;

public class A
{
	/*
	 * 在定义这个方法的时候不管未来是B类还是C类，为了通用，定义一种接口传接口即可
	 */
	public void print(PrintListener listener)
	{
		for (int i = 0; i < 10; i++)
		{
			System.out.println("循环到了：i = " + i);
			if (i == 5)
			{
				System.out.println("循环到了5了，该通知调用者了");
				listener.print();
			}
		}
	}
}
