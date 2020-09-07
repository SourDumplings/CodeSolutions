package com.cz.mashibing.juc.c_020;

import java.util.concurrent.Semaphore;

public class T11_TestSemaphore
{
    public static void main(String[] args)
    {
        // 允许 2 个线程同时可执行，即 Semaphore 用于限流
        // Semaphore s = new Semaphore(2);

        // 默认是非公平，可以设置为公平
        Semaphore s = new Semaphore(2, true);

        //允许一个线程同时可执行，即也实现了一种锁
        // Semaphore s = new Semaphore(1);

        new Thread(() ->
        {
            try
            {
                s.acquire(); // 将信号量许可证数减 1，即拿一个

                System.out.println("T1 running...");
                Thread.sleep(200);
                System.out.println("T1 running...");

            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            finally
            {
                s.release(); // 许可证释放掉，信号量许可证数加 1
            }
        }).start();

        new Thread(() ->
        {
            try
            {
                s.acquire();

                System.out.println("T2 running...");
                Thread.sleep(200);
                System.out.println("T2 running...");

                s.release();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }).start();
    }
}
