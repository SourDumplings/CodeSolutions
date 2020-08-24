/**
 * 一个同步方法可以调用另外一个同步方法，一个线程已经拥有某个对象的锁，再次申请的时候仍然会得到该对象的锁. 也就是说 synchronized 获得的锁是可重入的
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_009;

import java.util.concurrent.TimeUnit;

public class T
{
    synchronized void m1()
    {
        System.out.println("m1 start");
        try
        {
            TimeUnit.SECONDS.sleep(1);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        m2();
        System.out.println("m1 end");
    }

    synchronized void m2()
    {
        try
        {
            TimeUnit.SECONDS.sleep(2);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("m2");
    }

    public static void main(String[] args)
    {
        new T().m1();
        /*输出
        *   m1 start
            m2
            m1 end
           证明了 synchronized 是可重入锁，
           * 比如说有一个父类 F 中有 synchronized 方法 m，在子类 C 中被重写还是为 synchronized 方法，重写中调用了 super.m()
           * 如果 synchronized 是不可重入的，则会死锁，见 test
           */
    }
}
