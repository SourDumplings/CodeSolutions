/**
 * synchronized 关键字 对某个对象加锁
 *
 * @author mashibing
 */


package com.cz.mashibing.juc.c_004;

public class T
{

    private static int count = 10;

    public synchronized static void m()
    { //这里等同于 synchronized(T.class)
        count--;
        System.out.println(Thread.currentThread().getName() + " count = " + count);
    }

    public static void mm()
    {
        synchronized (T.class)
        { //考虑一下这里 synchronized(this) 是否可以？
            count--;
        }
    }

}
