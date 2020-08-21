package com.cz.mashibing.juc.c_000;

public class T03_Sleep_Yield_Join
{
    public static void main(String[] args)
    {
        // testSleep();
        // sleep 指的是线程睡眠，即当前线程暂停一段时间让给别的线程去运行
        // sleep 完了的线程会变成就绪态

        // testYield();
        // yield 指的是线程主动让出一下 CPU，变为就绪态，进入等待队列中

        testJoin();
        // join 指的是：如果有两个线程 t1 和 t2
        // 在 t1 的代码中出现了 t2.join()，则会导致 t1 加入到 t2 中去运行
        // 即 t2 运行完了 t1 才能继续运行
        // 即 join 用于等待另一个线程的结束
        // 例如主线程里依次调用 t1.join()，t2.join()，t3.join() 就可以保证先 t1 再 t2 再 t3
        // 或者 t3 一开始就调 t2.join()，t2 一开始就调 t1.join()，也可以保证 t1 -> t2 -> t3
    }

    static void testSleep()
    {
        new Thread(() ->
        {
            for (int i = 0; i < 100; i++)
            {
                System.out.println("A" + i);
                try
                {
                    Thread.sleep(500);
                    //TimeUnit.Milliseconds.sleep(500)
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    static void testYield()
    {
        new Thread(() ->
        {
            for (int i = 0; i < 100; i++)
            {
                System.out.println("A" + i);
                if (i % 10 == 0)
                {
                    Thread.yield();
                }


            }
        }).start();

        new Thread(() ->
        {
            for (int i = 0; i < 100; i++)
            {
                System.out.println("------------B" + i);
                if (i % 10 == 0)
                {
                    Thread.yield();
                }
            }
        }).start();
    }

    static void testJoin()
    {
        Thread t1 = new Thread(() ->
        {
            for (int i = 0; i < 100; i++)
            {
                System.out.println("A" + i);
                try
                {
                    Thread.sleep(0);
                    // Thread.sleep(500);
                    //TimeUnit.Milliseconds.sleep(500)
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        Thread t2 = new Thread(() ->
        {

            try
            {
                t1.join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }

            for (int i = 0; i < 100; i++)
            {
                System.out.println("B" + i);
                try
                {
                    Thread.sleep(500);
                    //TimeUnit.Milliseconds.sleep(500)
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        t1.start();
        t2.start();
    }
}
