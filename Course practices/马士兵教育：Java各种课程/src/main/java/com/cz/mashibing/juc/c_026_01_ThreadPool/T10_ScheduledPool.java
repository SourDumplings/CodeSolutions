package com.cz.mashibing.juc.c_026_01_ThreadPool;

/*
使用 DelayedWorkQueue 作为任务队列就是 ScheduledThreadPool，即定时任务线程池
即如果需要隔多少时间运行一次任务用这个
简单的定时用 Timer，复杂的要用定时器框架，比如 quartz，cron
* */

import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class T10_ScheduledPool
{
    public static void main(String[] args)
    {
        ScheduledExecutorService service = Executors.newScheduledThreadPool(4);
        service.scheduleAtFixedRate(() ->
        {
            try
            {
                TimeUnit.MILLISECONDS.sleep(new Random().nextInt(1000));
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName());
        }, 0, 500, TimeUnit.MILLISECONDS);

    }
}
