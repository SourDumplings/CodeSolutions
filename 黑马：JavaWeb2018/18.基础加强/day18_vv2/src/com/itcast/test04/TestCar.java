package com.itcast.test04;

public class TestCar
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		ICar car = new MyCar(new GoogleCar());
		car.start();
		car.run();
		car.stop();
	}

}
