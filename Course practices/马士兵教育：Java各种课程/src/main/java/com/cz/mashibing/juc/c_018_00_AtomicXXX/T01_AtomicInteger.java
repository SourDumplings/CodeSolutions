/**
 * 解决同样的问题的更高效的方法，使用AtomXXX类
 * AtomXXX类本身方法都是原子性的，但不能保证多个方法连续调用是原子性的
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_018_00_AtomicXXX;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;


public class T01_AtomicInteger
{
    /*volatile*/ //int count1 = 0;

    AtomicInteger count = new AtomicInteger(0);

    /*synchronized*/ void m()
    {
        for (int i = 0; i < 10000; i++)
        //if count1.get() < 1000
        {
            count.incrementAndGet(); //count1++
        }
    }

    public static void main(String[] args)
    {
        T01_AtomicInteger t = new T01_AtomicInteger();

        List<Thread> threads = new ArrayList<Thread>();

        for (int i = 0; i < 10; i++)
        {
            threads.add(new Thread(t::m, "thread-" + i));
        }

        threads.forEach((o) -> o.start());

        threads.forEach((o) ->
        {
            try
            {
                o.join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        });

        System.out.println(t.count);

        /* 会输出正确结果 100000
        * AtomicXXX 底层使用 CAS 算法
        * CAS 有 CPU 原语支持，中间不会被打断
        CAS(V, Expected, NewValue)
        	if V == E
        		V = New
        	Otherwise try again or fail
        常与自旋锁搭配使用，会有 ABA 问题，加版本号判断可以解决
        AtomicXXX 系列中有带版本号的类，例如 AtomicStampedReference
       	 */

    }

}
