package com.itcast.test07;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Arrays;

public class TestCar
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		ICar car = (ICar) Proxy.newProxyInstance(TestCar.class.getClassLoader(), GoogleCar.class.getInterfaces(),
				new InvocationHandler()
				{
					/*
					 * method代表执行的方法
					 * args代表执行的方法的参数
					 * Object代表方法执行完毕后的返回值
					 */
					public Object invoke(Object proxy, Method method, Object[] args) throws Throwable
					{
						// TODO Auto-generated method stub
						// method代表当前正在执行的每个方法
						// System.out.println(method.getName());
						
						// 代表方法执行完后返回的对象
						Object obj = null;
						
						// 增强start方法
						if (method.getName().equalsIgnoreCase("start"))
						{
							System.out.println("判断天气是否良好");

							// 打印args中的内容
							System.out.println(Arrays.toString(args));

							System.out.println("判断路况是否良好");
						}
						// 执行当前的方法
						obj = method.invoke(new GoogleCar(), args);
						return obj;
					}
				});

		String cc = car.start(1, 4);
		System.out.println("cc = " + cc);
		car.run();
		car.stop();
	}

}
