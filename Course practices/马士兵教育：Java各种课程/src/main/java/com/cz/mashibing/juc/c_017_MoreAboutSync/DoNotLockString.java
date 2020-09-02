/**
 * 不要以字符串常量作为锁定对象
 * 在下面的例子中，m1和m2其实锁定的是同一个对象
 * 这种情况还会发生比较诡异的现象，比如你用到了一个类库，在该类库中代码锁定了字符串“Hello”，
 * 但是你读不到源码，所以你在自己的代码中也锁定了"Hello",这时候就有可能发生非常诡异的死锁阻塞，
 * 因为你的程序和你用到的类库不经意间使用了同一把锁
 * <p>
 * jetty
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_017_MoreAboutSync;

import java.util.concurrent.TimeUnit;

public class DoNotLockString
{

    static String s1 = "Hello";
    static String s2 = "Hello";
    // static String s2 = "World";

    static void m1()
    {
        synchronized (s1)
        {
            while (true)
            {
                try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName());
            }
        }
    }

    static void m2()
    {
        synchronized (s2)
        {
            while (true)
            {
                try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName());
            }
        }
    }

    public static void main(String[] args)
    {
        new Thread(DoNotLockString::m1, "t1").start();
        new Thread(DoNotLockString::m2, "t2").start();
    }

}
