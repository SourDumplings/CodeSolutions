package com.itheima.test;

/**   
 * @ClassName:  Test   
 * @Description:TODO(普通方法，不适用接口回调)   
 * @author: SourDumplings
 * @date:   2019年3月6日 上午10:54:59   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public class Test
{
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		A a = new A();
		a.print(new B()); // 多态的体现
	}

}
