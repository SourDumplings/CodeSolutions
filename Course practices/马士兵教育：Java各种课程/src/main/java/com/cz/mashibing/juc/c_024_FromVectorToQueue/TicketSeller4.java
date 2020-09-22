/**
 * 有N张火车票，每张票都有一个编号
 * 同时有10个窗口对外售票
 * 请写一个模拟程序
 * <p>
 * 分析下面的程序可能会产生哪些问题？
 * 重复销售？超量销售？
 * <p>
 * 使用Vector或者Collections.synchronizedXXX
 * 分析一下，这样能解决问题吗？
 * <p>
 * 就算操作A和B都是同步的，但A和B组成的复合操作也未必是同步的，仍然需要自己进行同步
 * 就像这个程序，判断size和进行remove必须是一整个的原子操作
 * <p>
 * 使用ConcurrentQueue提高并发性
 *
 * @author 马士兵
 */
package com.cz.mashibing.juc.c_024_FromVectorToQueue;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

public class TicketSeller4
{
    /* Queue 这个接口设计的初衷就是为了应用于多线程环境的
    对于多线程容器往里面增删元素，多考虑 Queue 效率会比较高，
    少考虑 List */
    static Queue<String> tickets = new ConcurrentLinkedQueue<>();


    static
    {
        for (int i = 0; i < 1000; i++)
        {
            tickets.add("票 编号：" + i);
        }
    }

    public static void main(String[] args)
    {

        for (int i = 0; i < 10; i++)
        {
            new Thread(() ->
            {
                while (true)
                {
                    String s = tickets.poll();
                    if (s == null)
                    {
                        break;
                    }
                    else
                    {
                        System.out.println("销售了--" + s);
                    }
                }
            }).start();
        }
    }
}