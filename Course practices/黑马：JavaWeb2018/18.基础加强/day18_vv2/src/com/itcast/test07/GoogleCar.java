package com.itcast.test07;

// 相当于JDBC中MySQL中的驱动包，开发人员实现这个类
public final class GoogleCar implements ICar
{

	public String start(int a, int b)
	{
		// TODO Auto-generated method stub
		System.out.println("控制谷歌的汽车去启动");
		// 调用谷歌汽车提供的C语言函数
		return "start....." + a + " " + b;
	}

	public void run()
	{
		// TODO Auto-generated method stub
		System.out.println("控制谷歌的汽车去运行");
	}

	public void stop()
	{
		// TODO Auto-generated method stub
		System.out.println("控制谷歌的汽车去停止");
	}

}
