/**
 * 曾经的面试题：（淘宝？）
 * 实现一个容器，提供两个方法，add，size
 * 写两个线程，线程1添加10个元素到容器中，线程2实现监控元素的个数，当个数到5个时，线程2给出提示并结束
 * <p>
 * 给lists添加volatile之后，t2能够接到通知，但是，t2线程的死循环很浪费cpu，如果不用死循环，该怎么做呢？
 * <p>
 * 这里使用wait和notify做到，wait会释放锁，而notify不会释放锁
 * 需要注意的是，运用这种方法，必须要保证t2先执行，也就是首先让t2监听才可以
 * <p>
 * 阅读下面的程序，并分析输出结果
 * 可以读到输出结果并不是size=5时t2退出，而是t1结束时t2才接收到通知而退出
 * 想想这是为什么？
 * <p>
 * notify之后，t1必须释放锁，t2退出后，也必须notify，通知t1继续执行
 * 整个通信过程比较繁琐
 * <p>
 * 使用Latch（门闩）替代wait notify来进行通知
 * 好处是通信方式简单，同时也可以指定等待时间
 * 使用await和countdown方法替代wait和notify
 * CountDownLatch不涉及锁定，当count的值为零时当前线程继续运行
 * 当不涉及同步，只是涉及线程通信的时候，用synchronized + wait/notify就显得太重了
 * 这时应该考虑countdownlatch/cyclicbarrier/semaphore
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class T05_CountDownLatch
{

    // 添加volatile，使t2能够得到通知，个人感觉没必要加 volatile
    // volatile List lists = new ArrayList();

    List lists = new ArrayList();

    public void add(Object o)
    {
        lists.add(o);
    }

    public int size()
    {
        return lists.size();
    }

    public static void main(String[] args)
    {
        T05_CountDownLatch c = new T05_CountDownLatch();

        CountDownLatch latch = new CountDownLatch(1);

        new Thread(() ->
        {
            System.out.println("t2启动");
            if (c.size() != 5)
            {
                try
                {
                    latch.await();

                    //也可以指定等待时间
                    //latch.await(5000, TimeUnit.MILLISECONDS);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            System.out.println("t2 结束");

        }, "t2").start();

        try
        {
            TimeUnit.SECONDS.sleep(1);
        }
        catch (InterruptedException e1)
        {
            e1.printStackTrace();
        }

        new Thread(() ->
        {
            System.out.println("t1启动");
            for (int i = 0; i < 10; i++)
            {
                c.add(new Object());
                System.out.println("add " + i);

                if (c.size() == 5)
                {
                    // 打开门闩，让t2得以执行
                    latch.countDown();
                }
				/*
				* 如果有睡 1s，
				* 则打印正确结果：
				t2启动
				t1启动
				add 0
				add 1
				add 2
				add 3
				add 4
				t2 结束
				add 5
				add 6
				add 7
				add 8
				add 9

				如果没有睡 1s
				则会打印出错误结果：
				t2启动
				t1启动
				add 0
				add 1
				add 2
				add 3
				add 4
				add 5
				add 6
				t2 结束
				add 7
				add 8
				add 9
				这是因为 t1 打开门栓后 t2 还来不及打印
				t1 就继续添加新元素并打印了
				解决方法是使用两个门栓
				*
				* */
/*				try
				{
					TimeUnit.SECONDS.sleep(1);
				}
				catch (InterruptedException e)
				{
					e.printStackTrace();
				}*/
            }

        }, "t1").start();

    }
}