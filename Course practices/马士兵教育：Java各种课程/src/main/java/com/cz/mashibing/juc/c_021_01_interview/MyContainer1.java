/**
 * 面试题：写一个固定容量同步容器，拥有put和get方法，以及getCount方法，
 * 能够支持2个生产者线程以及10个消费者线程的阻塞调用
 * <p>
 * 使用wait和notify/notifyAll来实现
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_021_01_interview;

import java.util.LinkedList;
import java.util.concurrent.TimeUnit;

public class MyContainer1<T>
{
    final private LinkedList<T> lists = new LinkedList<>();
    final private int MAX = 10; //最多10个元素
    private int count = 0;


    public synchronized void put(T t)
    {
        while (lists.size() == MAX)
        {
            // 想想为什么用while而不是用if？
            // 如果用了 if，会再被叫醒之后不能再判断是否还是满的
            // 所以都必须用 while
            try
            {
                this.wait(); //effective java
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        lists.add(t);
        ++count;
        this.notifyAll();
        // 通知消费者线程进行消费
        // 这里使用 notifyAll 有个瑕疵
        // 使用 notifyAll 会叫醒 wait 等待队列的全部线程来抢锁，包括可能也在 wait 的生产者线程
		// 如果又是生产者线程，那它又会 wait，别的线程再抢锁
		// 能否只叫醒消费者线程而不叫醒生产者线程呢？
		// 这就需要两个条件，使用 Lock + Condition 类即可
		// 消费者线程类似
    }

    public synchronized T get()
    {
        T t = null;
        while (lists.size() == 0)
        {
            try
            {
                this.wait();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        t = lists.removeFirst();
        count--;
        this.notifyAll();
        // 通知生产者进行生产
        return t;
    }

    public static void main(String[] args)
    {
        MyContainer1<String> c = new MyContainer1<>();
        //启动消费者线程
        for (int i = 0; i < 10; i++)
        {
            new Thread(() ->
            {
                for (int j = 0; j < 5; j++)
                {
                    System.out.println(c.get());
                }
            }, "c" + i).start();
        }

        try
        {
            TimeUnit.SECONDS.sleep(2);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        //启动生产者线程
        for (int i = 0; i < 2; i++)
        {
            new Thread(() ->
            {
                for (int j = 0; j < 25; j++)
                {
                    c.put(Thread.currentThread().getName() + " " + j);
                }
            }, "p" + i).start();
        }
    }
}