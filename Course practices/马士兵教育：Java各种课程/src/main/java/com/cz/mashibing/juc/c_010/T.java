/**
 * 一个同步方法可以调用另外一个同步方法，一个线程已经拥有某个对象的锁，
 * 再次申请的时候仍然会得到该对象的锁. 也就是说synchronized获得的锁是可重入的
 * 这里是继承中有可能发生的情形，子类调用父类的同步方法
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_010;

import java.util.concurrent.TimeUnit;

public class T
{
    synchronized void m()
    {
        System.out.println("m start");
        try
        {
            TimeUnit.SECONDS.sleep(1);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("m end");
    }

    public static void main(String[] args)
    {
        new TT().m();
    }

}

class TT extends T
{
    @Override
    synchronized void m()
    {
        System.out.println("child m start");
        super.m();
        System.out.println("child m end");

        /*輸出:
        child m start
		m start
		m end
		child m end
		子类中会有一个指向父类的指针
		当子类中 synchronized 时锁的是 this
		子类中的方法调用带有 synchronized 的 super 的方法时
		还是锁 this，都是这个对象本身，即是一把锁*/
    }
}
