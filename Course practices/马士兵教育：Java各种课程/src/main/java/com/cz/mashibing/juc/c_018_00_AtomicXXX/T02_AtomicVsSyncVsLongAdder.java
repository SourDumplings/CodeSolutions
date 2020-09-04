package com.cz.mashibing.juc.c_018_00_AtomicXXX;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;
import java.util.concurrent.atomic.LongAdder;

/* 输出结果：
Atomic: 100000000 time 2189
Sync: 100000000 time 3830
LongAdder: 100000000 time 317

Atomic 比 Sync 效率高是因为 Atomic 不加锁，采用 CAS，这种情形下效率高
而 Sync 使用重量级锁
LongAddr 效率高是因为其内部使用了分段锁（这里是分成多个 CAS），比如分出四个数 0，使用 4 把锁分别加这四个数，
然后将结果加在一起即可，LongAddr 适用于超高并发情况
*
* */

public class T02_AtomicVsSyncVsLongAdder
{
    static long count2 = 0L;
    static AtomicLong count1 = new AtomicLong(0L);
    static LongAdder count3 = new LongAdder();

    public static void main(String[] args) throws Exception
    {
        Thread[] threads = new Thread[1000];

        for (int i = 0; i < threads.length; i++)
        {
            threads[i] =
                new Thread(() ->
                {
                    for (int k = 0; k < 100000; k++)
                    {
                        count1.incrementAndGet();
                    }
                });
        }

        long start = System.currentTimeMillis();

        for (Thread t : threads)
        {
            t.start();
        }

        for (Thread t : threads)
        {
            t.join();
        }

        long end = System.currentTimeMillis();

        //TimeUnit.SECONDS.sleep(10);

        System.out.println("Atomic: " + count1.get() + " time " + (end - start));
        //-----------------------------------------------------------
        Object lock = new Object();

        for (int i = 0; i < threads.length; i++)
        {
            threads[i] =
                new Thread(new Runnable()
                {
                    @Override
                    public void run()
                    {

                        for (int k = 0; k < 100000; k++)
                        {
                            synchronized (lock)
                            {
                                count2++;
                            }
                        }
                    }
                });
        }

        start = System.currentTimeMillis();

        for (Thread t : threads)
        {
            t.start();
        }

        for (Thread t : threads)
        {
            t.join();
        }

        end = System.currentTimeMillis();

        System.out.println("Sync: " + count2 + " time " + (end - start));

        //----------------------------------
        for (int i = 0; i < threads.length; i++)
        {
            threads[i] =
                new Thread(() ->
                {
                    for (int k = 0; k < 100000; k++)
                    {
                        count3.increment();
                    }
                });
        }

        start = System.currentTimeMillis();

        for (Thread t : threads)
        {
            t.start();
        }

        for (Thread t : threads)
        {
            t.join();
        }

        end = System.currentTimeMillis();

        //TimeUnit.SECONDS.sleep(10);

        System.out.println("LongAdder: " + count1.longValue() + " time " + (end - start));

    }

    static void microSleep(int m)
    {
        try
        {
            TimeUnit.MICROSECONDS.sleep(m);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }

}
