package com.cz.mashibing.juc.c_020;

import java.util.concurrent.Exchanger;

public class T12_TestExchanger
{

    static Exchanger<String> exchanger = new Exchanger<>();

    public static void main(String[] args)
    {
        new Thread(() ->
        {
            String s = "T1";
            try
            {
                s = exchanger.exchange(s);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName() + " " + s);

        }, "t1").start();

        new Thread(() ->
        {
            String s = "T2";
            try
            {
                s = exchanger.exchange(s);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName() + " " + s);

        }, "t2").start();

        /*
        * 输出结果：
            t2 T1
            t1 T2
          即两个 s 交换了，
          这是线程通信，交换数据的一种方式
          如果第二个线程不 start 则第一个线程会阻塞
          故 Exchanger 其实是一种 2 个 parties 的 CyclicBarrier
        * */

    }
}
