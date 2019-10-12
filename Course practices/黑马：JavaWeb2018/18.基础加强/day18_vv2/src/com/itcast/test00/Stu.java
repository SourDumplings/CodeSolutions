package com.itcast.test00;

// 单例
public class Stu
{
	private Stu()
	{
		
	}
	
	private static Stu stu = new Stu();
	
	public static Stu getInstance()
	{
		return stu;
	}
	
/*	@Override
	public String toString()
	{
		return "11";
	}*/
}
