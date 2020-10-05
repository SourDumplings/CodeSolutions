/*
Condition本质是锁资源上不同的等待队列
使用多个 Condition 可以用来指定唤醒特定的线程，
这个问题没区别但是对于多个线程需要控制的话有用，例如生产者消费者问题
这种写法没有保证谁先输出
 */
package com.cz.mashibing.juc.c_026_00_interview.A1B2C3;


import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class T09_00_lock_condition
{

    public static void main(String[] args)
    {

        char[] aI = "1234567".toCharArray();
        char[] aC = "ABCDEFG".toCharArray();

        Lock lock = new ReentrantLock();
        Condition conditionT1 = lock.newCondition();
        Condition conditionT2 = lock.newCondition();

        new Thread(() ->
        {
            try
            {
                lock.lock();

                for (char c : aI)
                {
                    System.out.print(c);
                    conditionT2.signal();
                    conditionT1.await();
                }

                conditionT2.signal();

            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
            finally
            {
                lock.unlock();
            }

        }, "t1").start();

        new Thread(() ->
        {
            try
            {
                lock.lock();

                for (char c : aC)
                {
                    System.out.print(c);
                    conditionT1.signal();
                    conditionT2.await();
                }

                conditionT1.signal();

            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
            finally
            {
                lock.unlock();
            }

        }, "t2").start();
    }
}


