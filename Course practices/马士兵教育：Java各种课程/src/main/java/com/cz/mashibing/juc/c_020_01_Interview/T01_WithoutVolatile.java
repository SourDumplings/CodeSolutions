/**
 * 曾经的面试题：（淘宝？）
 * 实现一个容器，提供两个方法，add，size
 * 写两个线程，线程1添加10个元素到容器中，线程2实现监控元素的个数，当个数到5个时，线程2给出提示并结束
 * <p>
 * 分析下面这个程序，能完成这个功能吗？
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;


public class T01_WithoutVolatile
{

    List lists = new ArrayList();

    public void add(Object o)
    {
        lists.add(o);
    }

    public int size()
    {
        return lists.size();
    }

    public static void main(String[] args)
    {
        T01_WithoutVolatile c = new T01_WithoutVolatile();

        new Thread(() ->
        {
            for (int i = 0; i < 10; i++)
            {
                c.add(new Object());
                System.out.println("add " + i);

                try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        }, "t1").start();

        new Thread(() ->
        {
            while (true)
            {
                if (c.size() == 5)
                {
                    break;
                }
            }
            System.out.println("t2 结束");
        }, "t2").start();
    }
}

/*
* 输出：
add 0
add 1
add 2
add 3
add 4
add 5
add 6
add 7
add 8
add 9
线程 t2 永远没法结束
因为 ArrayList 不是线程安全的，
t1 往里面加了元素 size 没有及时更新就可能被读了，
这样导致 size == 5 可能永远没有被 t2 读到.
* */