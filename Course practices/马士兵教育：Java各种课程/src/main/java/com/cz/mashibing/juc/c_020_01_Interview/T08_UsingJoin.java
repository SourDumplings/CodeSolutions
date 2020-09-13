package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.ArrayList;
import java.util.List;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 马士兵教育：Java各种课程
 * @date 2020/9/13 10:48
 */
public class T08_UsingJoin
{
    // 添加volatile，使t2能够得到通知，个人感觉没必要加 volatile
    // volatile List lists = new ArrayList();

    List lists = new ArrayList();

    public void add(Object o)
    {
        lists.add(o);
    }

    public int size()
    {
        return lists.size();
    }

    static Thread t1 = null, t2 = null;

    public static void main(String[] args)
    {
        T08_UsingJoin c = new T08_UsingJoin();

        t1 = new Thread(() ->
        {
            for (int i = 0; i < 5; i++)
            {
                c.add(new Object());
                System.out.println("add " + i);
            }

            t2.start();
            try
            {
                t2.join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            for (int i = 5; i < 10; i++)
            {
                System.out.println(i);
            }

        }, "t1");

        t2 = new Thread(() ->
        {
            System.out.println("t2 结束");
        }, "t2");

        t1.start();
    }
}
