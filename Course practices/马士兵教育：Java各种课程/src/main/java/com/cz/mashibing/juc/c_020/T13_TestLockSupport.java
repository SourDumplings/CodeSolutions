package com.cz.mashibing.juc.c_020;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.LockSupport;

public class T13_TestLockSupport
{
    public static void main(String[] args)
    {
        Thread t = new Thread(() ->
        {
            for (int i = 0; i < 10; i++)
            {
                System.out.println(i);
                // if (i == 5)
                if (i == 5 || i == 7)
                {
                    // 当前线程停止
                    LockSupport.park();
                }
                try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        t.start();

/*        try
        {
            TimeUnit.SECONDS.sleep(8);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("after 8 senconds!");*/

        LockSupport.unpark(t); // 让线程继续

        /* LoclSupport 提供了对线程的控制功能，
        * 是为了实现锁而定的
        * 如果没有等 8 秒的代码那么 t 线程不会停了
        * 即 unpark 可以在 park 之前调用，表示提前放行一次
        * 但是如果要停两次，即 i == 5 || i == 7 的时候停
        * 这样 unpark 还是无法阻止停在 i == 7 的时候，因为其本质是维护了一个计数器
        * 故比使用锁更灵活 */

    }
}
