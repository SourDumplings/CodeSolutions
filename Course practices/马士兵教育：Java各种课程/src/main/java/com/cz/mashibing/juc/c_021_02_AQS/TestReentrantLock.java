package com.cz.mashibing.juc.c_021_02_AQS;

import java.util.concurrent.locks.ReentrantLock;

/*
* 用于追踪动态阅读 AQS 源码，
* 使用 JDK 11
* */

public class TestReentrantLock
{

    private static volatile int i = 0;

    public static void main(String[] args)
    {
        ReentrantLock lock = new ReentrantLock();
        lock.lock();
        //synchronized (TestReentrantLock.class) {
        i++;
        //}

        lock.unlock();

        //synchronized 程序员的丽春院 JUC
    }
}
