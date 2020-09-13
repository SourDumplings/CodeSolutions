package com.cz.mashibing.juc.c_026_00_interview.A1B2C3;

import java.util.concurrent.atomic.AtomicInteger;

public class T01_00_Question
{
    public static void main(String[] args)
    {
        //要求用2个线程顺序打印A1B2C3....Z26

        AtomicInteger count = new AtomicInteger(1);

        Thread t1 = null;
        final Object lock = new Object();
        final Thread t2 = new Thread(() ->
        {
            synchronized (lock)
            {
                while (count.get() < 27)
                {
                    System.out.print(count.getAndIncrement());
                    lock.notify();
                    if (count.get() >= 27)
                    {
                        break;
                    }
                    try
                    {
                        lock.wait();
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }
            }
        }, "t2");

        t1 = new Thread(() ->
        {
            synchronized (lock)
            {
                t2.start();
                while (count.get() < 27)
                {
                    System.out.print((char) (count.get() + 'A' - 1));
                    lock.notify();
                    try
                    {
                        lock.wait();
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }
            }
        }, "t1");
        t1.start();


    }
}
