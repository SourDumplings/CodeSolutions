package com.cz.mashibing.juc.c_026_00_interview.A1B2C3;


import java.util.concurrent.CountDownLatch;

public class T07_00_sync_wait_notify_CountDownLatch
{

    private static CountDownLatch latch = new CountDownLatch(1);

    public static void main(String[] args)
    {
        final Object o = new Object();

        char[] aI = "1234567".toCharArray();
        char[] aC = "ABCDEFG".toCharArray();

        new Thread(() ->
        {
            try
            {
                latch.await();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }

            synchronized (o)
            {

                for (char c : aI)
                {
                    System.out.print(c);
                    try
                    {
                        o.notify();
                        o.wait();
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }

                o.notify();
            }
        }, "t1").start();

        new Thread(() ->
        {

            synchronized (o)
            {
                for (char c : aC)
                {
                    System.out.print(c);
                    latch.countDown();
                    try
                    {
                        o.notify();
                        o.wait();
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }
                o.notify();
            }
        }, "t2").start();
    }
}


