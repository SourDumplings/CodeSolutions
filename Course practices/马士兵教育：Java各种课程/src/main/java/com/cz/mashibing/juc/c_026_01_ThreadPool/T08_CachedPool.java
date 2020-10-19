package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

/*
* CachedThreadPool 是来一个任务必须马上要有一个线程来执行
* 没有空闲线程了就会启动一个线程，看源码使用了 SynchronousQueue 可知
* 不建议用这个，因为有可能启动的线程非常多（因为用了 Integer.MAX_VALUE），导致 CPU 全都耗费到线程切换上了
* */

public class T08_CachedPool
{
    public static void main(String[] args) throws InterruptedException
    {
        ExecutorService service = Executors.newCachedThreadPool();
        System.out.println(service);
        for (int i = 0; i < 2; i++)
        {
            service.execute(() ->
            {
                try
                {
                    TimeUnit.MILLISECONDS.sleep(500);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName());
            });
        }
        System.out.println(service);

        TimeUnit.SECONDS.sleep(80);

        System.out.println(service);


    }
}
