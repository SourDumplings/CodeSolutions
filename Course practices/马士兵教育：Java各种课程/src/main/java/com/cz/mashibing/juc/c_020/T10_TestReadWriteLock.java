package com.cz.mashibing.juc.c_020;

import java.util.Random;
import java.util.concurrent.atomic.LongAdder;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class T10_TestReadWriteLock
{
    static Lock lock = new ReentrantLock();
    private static int value;

    static ReadWriteLock readWriteLock = new ReentrantReadWriteLock();
    static Lock readLock = readWriteLock.readLock();
    static Lock writeLock = readWriteLock.writeLock();

    /*
     * 读写锁即共享锁+排他锁
     * */

    public static void read(Lock lock)
    {
        try
        {
            lock.lock();
            Thread.sleep(1000);
            System.out.println("read over!");
            //模拟读取操作
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        finally
        {
            lock.unlock();
        }
    }

    public static void write(Lock lock, int v)
    {
        try
        {
            lock.lock();
            Thread.sleep(1000);
            value = v;
            System.out.println("write over!");
            //模拟写操作
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        finally
        {
            lock.unlock();
        }
    }


    public static void main(String[] args)
    {
        // Runnable readR = ()-> read(lock);
        Runnable readR = () -> read(readLock);

        // Runnable writeR = ()->write(lock, new Random().nextInt());
        Runnable writeR = () -> write(writeLock, new Random().nextInt());

        for (int i = 0; i < 18; i++)
        {
            new Thread(readR).start();
        }
        for (int i = 0; i < 2; i++)
        {
            new Thread(writeR).start();
        }

        /* 执行结果，如果用互斥锁（排他锁），就得等 20 秒才能完事，
        * 但是用读写锁就能快很多，几乎 1 秒全部结束 */

    }
}
