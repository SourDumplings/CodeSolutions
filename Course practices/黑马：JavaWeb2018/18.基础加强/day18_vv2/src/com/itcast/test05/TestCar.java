package com.itcast.test05;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class TestCar
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
/*		// 获取GoogleCar.class字节码文件上所有的接口
		Class[] clazz = GoogleCar.class.getInterfaces();
		// 由于当前案例中GoogleCar仅实现了一个接口ICar，这样就相当于
		// 得到ICar.class字节码对象
		Class cla = clazz[0];
		// 获取ICar.class字节码对象上所有的方法
		Method[] mds = clazz[0].getMethods();
		for (Method method : mds)
		{
			System.out.println(method.getName());
		}*/
		
		// 对于GoogleCar的特有方法，装饰者模式和动态代理模式都增强不了
		
		// 第一个参数：固定值，告诉虚拟机用哪个字节码加载器加载内存中创建出的字节码文件
		// 第二个参数：告诉虚拟机内存中正在被创建的字节码文件中应该有哪些方法
		// 第三个参数：告诉虚拟机底层正在被创建的各个方法如何来处理
		ICar car = (ICar) Proxy.newProxyInstance(TestCar.class.getClassLoader(), GoogleCar.class.getInterfaces(), new InvocationHandler()
				{
					public Object invoke(Object proxy, Method method, Object[] args) throws Throwable
					{
						// TODO Auto-generated method stub
						// method代表当前正在执行的每个方法
//						System.out.println(method.getName());

						
						// 增强start方法
						if (method.getName().equalsIgnoreCase("start"))
						{
							System.out.println("判断天气是否良好");
							System.out.println("判断路况是否良好");
						}
						// 执行当前的方法
						method.invoke(new GoogleCar(), args);
						return null;
					}
				});
		
		car.start();
		car.run();
		car.stop();
		
	}

}
