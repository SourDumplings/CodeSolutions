package com.cz.mashibing.juc.c_000;

import java.util.concurrent.TimeUnit;

public class T01_WhatIsThread
{
    private static class T1 extends Thread
    {
        @Override
        public void run()
        {
            for (int i = 0; i < 10; i++)
            {
                try
                {
                    TimeUnit.MICROSECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
                System.out.println("T1");
            }
        }
    }

    public static void main(String[] args)
    {
        // new T1().run();
        // 会先输出 10 个 T1 再输出 main


        new T1().start();
        // 会 T1 和 main 交替输出
        // 线程 T1 和主线程交替执行

        for (int i = 0; i < 10; i++)
        {
            try
            {
                TimeUnit.MICROSECONDS.sleep(1);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            System.out.println("main");
        }

    }
}
