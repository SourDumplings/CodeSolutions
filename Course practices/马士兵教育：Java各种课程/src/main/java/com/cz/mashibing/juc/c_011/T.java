/**
 * 程序在执行过程中，如果出现异常，默认情况锁会被释放 所以，在并发处理的过程中，有异常要多加小心，不然可能会发生不一致的情况。 比如，在一个web
 * app处理过程中，多个servlet线程共同访问同一个资源，这时如果异常处理不合适， 在第一个线程中抛出异常，其他线程就会进入同步代码区，有可能会访问到异常产生时的数据。
 * 因此要非常小心的处理同步业务逻辑中的异常
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_011;

import java.util.concurrent.TimeUnit;

public class T
{
    int count = 0;

    synchronized void m()
    {
        System.out.println(Thread.currentThread().getName() + " start");
        while (true)
        {
            count++;
            System.out.println(Thread.currentThread().getName() + " count = " + count);
            try
            {
                TimeUnit.SECONDS.sleep(1);

            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }

            if (count == 5)
            {
                int i = 1 / 0; //此处抛出异常，锁将被释放，要想不被释放，可以在这里进行catch，然后让循环继续
                System.out.println(i);
            }
        }
    }

    public static void main(String[] args)
    {
        T t = new T();
        Runnable r = new Runnable()
        {

            @Override
            public void run()
            {
                t.m();
            }

        };
        new Thread(r, "t1").start();

        try
        {
            TimeUnit.SECONDS.sleep(3);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        new Thread(r, "t2").start();

      /* 输出为：
        t1 start
		t1 count = 1
		t1 count = 2
		t1 count = 3
		t1 count = 4
		t1 count = 5
		Exception in thread "t1" java.lang.ArithmeticException: / by zero
			at com.cz.mashibing.juc.c_011.T.m(T.java:35)
			at com.cz.mashibing.juc.c_011.T$1.run(T.java:50)
			at java.lang.Thread.run(Thread.java:748)
		t2 start
		t2 count = 6
		t2 count = 7
		t2 count = 8
		即由于 t1 抛出了异常导致了 t1 的锁被释放，让 t2 给拿到了。
      * */
    }

}


