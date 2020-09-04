/**
 * reentrantlock用于替代synchronized
 * synchronized 本身就是可重入锁的一种
 * synchronized 必须是可重入的，否则子类调用父类都是 synchronized 方法无法实现，见C_009 Test
 * 本例中由于m1锁定this,只有m1执行完毕的时候,m2才能执行
 * 这里是复习synchronized最原始的语义
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020;

import java.util.concurrent.TimeUnit;

public class T01_ReentrantLock1
{
    synchronized void m1()
    {
        for (int i = 0; i < 10; i++)
        {
            try
            {
                TimeUnit.SECONDS.sleep(1);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            System.out.println(i);
            if (i == 2)
            {
                m2();
            }
        }

    }

    synchronized void m2()
    {
        System.out.println("m2 ...");
    }

    public static void main(String[] args)
    {
        T01_ReentrantLock1 rl = new T01_ReentrantLock1();
        new Thread(rl::m1).start();
        try
        {
            TimeUnit.SECONDS.sleep(1);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

		/* 使用同一个线程时输出：
		0
		1
		2
		m2 ...
		3
		4
		5
		6
		7
		8
		9
		证明了 synchronized 是可重入锁，否则 m2 不可能执行
		*/

        // new Thread(rl::m2).start();
		/*
		使用两个线程时输出：
		0
		1
		2
		m2 ...
		3
		4
		5
		6
		7
		8
		9
		m2 ...
		可以看到第二个线程需要等待第一个线程执行完了才能执行
		由此也证明了锁的拥有者是线程，可重入是以线程为主体的
		* */
    }
}