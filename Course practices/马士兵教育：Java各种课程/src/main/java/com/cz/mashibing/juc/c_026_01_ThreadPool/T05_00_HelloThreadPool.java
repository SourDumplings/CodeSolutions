package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.io.IOException;
import java.util.concurrent.*;

public class T05_00_HelloThreadPool
{

    static class Task implements Runnable
    {
        private int i;

        public Task(int i)
        {
            this.i = i;
        }

        @Override
        public void run()
        {
            System.out.println(Thread.currentThread().getName() + " Task " + i);
            try
            {
                System.in.read(); // 阻塞于此
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }

        @Override
        public String toString()
        {
            return "Task{" +
                "i=" + i +
                '}';
        }
    }

    public static void main(String[] args)
    {
        /* 线程池中维护了两个集合：线程集合和任务队列 */
        ThreadPoolExecutor tpe = new ThreadPoolExecutor(2, // 核心线程数，即保持多少个线程
            4, // 最大线程数，即最多扩展到有多少个线程
            60, // 线程多长时间空闲就归还给操作系统直到线程数达到核心线程数，即默认下核心线程不归还，即默认下核心线程永远活着
            TimeUnit.SECONDS,
            new ArrayBlockingQueue<Runnable>(4), // 任务队列，必须是阻塞队列
            Executors.defaultThreadFactory(), // 线程工厂对象，即线程产生器，这个一般都会自定义，有命名规范
            new ThreadPoolExecutor.CallerRunsPolicy()); // 拒绝策略，线程池中线程全忙且达到了最大线程数，并且任务队列满，这时启动拒绝策略，一般都会自定义

        for (int i = 0; i < 8; i++)
        {
            tpe.execute(new Task(i));
        }

        System.out.println(tpe.getQueue());

        tpe.execute(new Task(100));

        System.out.println(tpe.getQueue());

        tpe.shutdown();
    }
}
