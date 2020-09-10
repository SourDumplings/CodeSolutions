/**
 * 曾经的面试题：（淘宝？）
 * 实现一个容器，提供两个方法，add，size
 * 写两个线程，线程1添加10个元素到容器中，线程2实现监控元素的个数，当个数到5个时，线程2给出提示并结束
 * <p>
 * 给lists添加volatile之后，t2能够接到通知，但是，t2线程的死循环很浪费cpu，如果不用死循环，
 * 而且，如果在if 和 break之间被别的线程打断，得到的结果也不精确，
 * 该怎么做呢？
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.TimeUnit;


public class T02_WithVolatile
{

    //添加 volatile，使t2能够得到通知
	/* 输出：
	add 0
	add 1
	add 2
	add 3
	add 4
	t2 结束
	add 5
	add 6
	add 7
	add 8
	add 9
	得到了正确的输出，按理说 volatile 修饰的是引用，
	引用里面的对象变了用 volatile 是没有用的，输出正确是一种偶然性，
	如果把睡眠 1s 去掉便很大可能不能得到正确的输出了
	*/
    // volatile List lists = new LinkedList();

	/* 用这个方法也没有用，比较诡异
	* 如果不睡 1s 还是不能保证得到正确结果，
	* 只能解释为可能是 hotspot 实现时会在另一个线程睡觉时更新
	* 因此 volatile 慎用，不要用于修饰引用 */
    volatile List lists = Collections.synchronizedList(new LinkedList<>());


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

        T02_WithVolatile c = new T02_WithVolatile();
        new Thread(() ->
        {
            for (int i = 0; i < 10; i++)
            {
                c.add(new Object());
                System.out.println("add " + i);

                /*try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }*/
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