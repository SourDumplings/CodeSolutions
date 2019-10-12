package com.itcast.test00;

public class TestStu
{
	public static void main(String[] args)
	{
		Stu stu1 = Stu.getInstance();
		Stu stu2 = Stu.getInstance();
		Stu stu3 = Stu.getInstance();
		// 打印三个对象对应的类@哈希值，说明三个对象的引用指向的是同一个
		System.out.println(stu1);
		System.out.println(stu2);
		System.out.println(stu3);
	}
}
