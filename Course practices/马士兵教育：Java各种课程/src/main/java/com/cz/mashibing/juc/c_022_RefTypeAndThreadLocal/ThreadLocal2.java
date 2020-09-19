/**
 * ThreadLocal线程局部变量
 * <p>
 * ThreadLocal是使用空间换时间，synchronized是使用时间换空间
 * 比如在hibernate中session就存在与ThreadLocal中，避免synchronized的使用
 * 声明式事务也会使用 ThreadLocal，避免拿到多个 Connection
 * <p>
 * 运行下面的程序，理解ThreadLocal
 *
 * @author 马士兵
 */
package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

import java.util.concurrent.TimeUnit;

public class ThreadLocal2
{
    //volatile static Person p = new Person();
    static ThreadLocal<Person> tl = new ThreadLocal<>();

    public static void main(String[] args)
    {

        new Thread(() ->
        {
            try
            {
                TimeUnit.SECONDS.sleep(2);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }

            System.out.println(tl.get());
            /*
            输出 null
            即线程 t2 set 的 Person t1 是拿不到的
            即 ThreadLocal 会使得对象变成线程独有
            * */
        }).start();

        new Thread(() ->
        {
            try
            {
                TimeUnit.SECONDS.sleep(1);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            tl.set(new Person());
        }).start();
    }

    static class Person
    {
        String name = "zhangsan";
    }
}


