/**
 * ͬ同步和非同步方法可以同时调用吗？ 可以
 *
 * @author mashibing
 */

package com.cz.mashibing.juc.c_007;

public class T
{

    public synchronized void m1()
    {
        System.out.println(Thread.currentThread().getName() + " m1 start...");
        try
        {
            Thread.sleep(10000);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println(Thread.currentThread().getName() + " m1 end");
    }

    public void m2()
    {
        try
        {
            Thread.sleep(5000);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println(Thread.currentThread().getName() + " m2 ");
    }

    public static void main(String[] args)
    {
        T t = new T();
		
		/*new Thread(()->t.m1(), "t1").start();
		new Thread(()->t.m2(), "t2").start();*/

		// Java 8 中引入了方法引用 ::
        new Thread(t::m1, "t1").start();
        new Thread(t::m2, "t2").start();
		
		/*
		//1.8֮ 之前的写法
		new Thread(new Runnable() {

			@Override
			public void run() {
				t.m1();
			}
			
		});
		*/

		/*输出为
		* t1 m1 start...
		  t2 m2
          t1 m1 end
          m2 可以在执行 m1 的中间执行，即同步方法和非同步方法可以同时进行调用*/
    }

}
