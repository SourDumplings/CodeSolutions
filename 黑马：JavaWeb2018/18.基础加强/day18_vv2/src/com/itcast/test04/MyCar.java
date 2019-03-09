package com.itcast.test04;

public class MyCar implements ICar
{
	ICar car;
	
	public MyCar(ICar car)
	{
		this.car = car;
	}
	
	public void start()
	{
		// TODO Auto-generated method stub
		System.out.println("判断天气是否良好");
		System.out.println("判断路况是否良好");
		car.start();
	}

	public void run()
	{
		// TODO Auto-generated method stub
		car.run();
	}

	public void stop()
	{
		// TODO Auto-generated method stub
		car.stop();
	}
	
}
