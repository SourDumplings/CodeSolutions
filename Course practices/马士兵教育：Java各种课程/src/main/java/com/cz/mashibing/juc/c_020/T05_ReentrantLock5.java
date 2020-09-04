/**
 * reentrantlock用于替代synchronized
 * 由于m1锁定this,只有m1执行完毕的时候,m2才能执行
 * 这里是复习synchronized最原始的语义
 * <p>
 * 使用reentrantlock可以完成同样的功能
 * 需要注意的是，必须要必须要必须要手动释放锁（重要的事情说三遍）
 * 使用syn锁定的话如果遇到异常，jvm会自动释放锁，但是lock必须手动释放锁，因此经常在finally中进行锁的释放
 * <p>
 * 使用reentrantlock可以进行“尝试锁定”tryLock，这样无法锁定，或者在指定时间内无法锁定，线程可以决定是否继续等待
 * <p>
 * 使用ReentrantLock还可以调用lockInterruptibly方法，可以对线程interrupt方法做出响应，
 * 在一个线程等待锁的过程中，可以被打断
 * <p>
 * ReentrantLock还可以指定为公平锁（默认非公平），即先来先服务，后来的线程先进队列，轮到你了再申请锁
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020;

import java.util.concurrent.locks.ReentrantLock;

public class T05_ReentrantLock5 extends Thread
{

    // private static ReentrantLock lock = new ReentrantLock(true); //参数为true表示为公平锁，请对比输出结果
    private static ReentrantLock lock = new ReentrantLock();

    /*
    无论是否是公平锁，都会出现两个线程交替的情况
    公平锁交替频率高得多，
    这是因为 t1 释放一次所之后可以再进等待队列，
    由于偏向锁的机制导致非公平锁下先抢到锁的线程优先
    公平锁只是保证先进队列的先去抢锁
    synchronized 只有非公平锁
    */

    public void run()
    {
        for (int i = 0; i < 100; i++)
        {
            lock.lock();
            try
            {
                System.out.println(Thread.currentThread().getName() + "获得锁");
            }
            finally
            {
                lock.unlock();
            }
        }
    }

    public static void main(String[] args)
    {
        T05_ReentrantLock5 rl = new T05_ReentrantLock5();
        Thread th1 = new Thread(rl);
        Thread th2 = new Thread(rl);
        th1.start();
        th2.start();
    }
}