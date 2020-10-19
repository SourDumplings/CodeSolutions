package com.cz.mashibing.juc.c_026_01_ThreadPool;

/*
* 为什么要有单线程的线程池：
* 1.任务队列管理
* 2.生命周期管理
* */

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class T07_SingleThreadPool
{
    public static void main(String[] args)
    {
        // 线程池的工厂工具类 Executors
        ExecutorService service = Executors.newSingleThreadExecutor();
        for (int i = 0; i < 5; i++)
        {
            final int j = i;
            service.execute(() ->
            {

                System.out.println(j + " " + Thread.currentThread().getName());
            });
        }

    }
}
