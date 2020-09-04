package com.cz.mashibing.juc.c_020;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.LongAdder;

public class T06_TestCountDownLatch
{
    private static LongAdder result = new LongAdder();

    public static void main(String[] args)
    {
        // usingJoin();
        usingCountDownLatch();
        // usingNothing();
        System.out.println(result);

        /* 输出结果：
        使用 join() 或者 countDownLatch 会输出 1000000，
         啥都不用的话输出的是错乱的结果 */
    }

    private static void usingCountDownLatch()
    {
        Thread[] threads = new Thread[100];
        CountDownLatch latch = new CountDownLatch(threads.length);

        for (int i = 0; i < threads.length; i++)
        {
            threads[i] = new Thread(() ->
            {
                for (int j = 0; j < 10000; j++)
                {
                    result.increment();
                }
                latch.countDown(); // 这个是原子操作
            });
        }

        for (int i = 0; i < threads.length; i++)
        {
            threads[i].start();
        }

        try
        {
            latch.await();
            /* 这里即就是 latch 拴住，等到每个线程都结束了（即 count 减到 0）再继续
             * 同样的事情用 join() 也可以实现，
             * 但是用 Latch 要灵活，因为我完全可以在一个线程中将 count 减到 0 */
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        System.out.println("end latch");
    }

    private static void usingJoin()
    {
        Thread[] threads = new Thread[100];

        for (int i = 0; i < threads.length; i++)
        {
            threads[i] = new Thread(() ->
            {
                for (int j = 0; j < 10000; j++)
                {
                    result.increment();
                }
            });
        }

        for (int i = 0; i < threads.length; i++)
        {
            threads[i].start();
        }

        for (int i = 0; i < threads.length; i++)
        {
            try
            {
                threads[i].join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        System.out.println("end join");
    }

    private static void usingNothing()
    {
        Thread[] threads = new Thread[100];

        for (int i = 0; i < threads.length; i++)
        {
            threads[i] = new Thread(() ->
            {
                for (int j = 0; j < 10000; j++)
                {
                    result.increment();
                }
            });
        }

        for (int i = 0; i < threads.length; i++)
        {
            threads[i].start();
        }
        System.out.println("end nothing");
    }
}
