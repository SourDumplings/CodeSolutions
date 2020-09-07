package com.cz.mashibing.juc.c_020;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

/*  CyclicBarrier 可以用来做批量通行
* */

public class T07_TestCyclicBarrier
{
    public static void main(String[] args)
    {
        //CyclicBarrier barrier = new CyclicBarrier(20);

        CyclicBarrier barrier = new CyclicBarrier(20, () -> System.out.println("满人，发车"));

/*        CyclicBarrier barrier = new CyclicBarrier(20, new Runnable()
        {
            @Override
            public void run()
            {
                System.out.println("满人，发车");
            }
        });*/

        for (int i = 0; i < 80; i++)
        {

            new Thread(() ->
            {
                try
                {
                    barrier.await();

                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
                catch (BrokenBarrierException e)
                {
                    e.printStackTrace();
                }
            }).start();

        }
    }
}