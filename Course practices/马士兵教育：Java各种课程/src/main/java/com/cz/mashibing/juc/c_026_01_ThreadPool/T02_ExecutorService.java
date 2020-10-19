/**
 * 认识ExecutorService,阅读API文档
 * 所有的线程池都要实现 ExecutorService 接口
 * 认识submit方法，扩展了execute方法，具有一个返回值
 */
package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class T02_ExecutorService
{
    public static void main(String[] args)
    {
        ExecutorService e = Executors.newCachedThreadPool();
    }
}