package com.cz.mashibing.juc.c_025;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

public class T04_ConcurrentQueue
{
    public static void main(String[] args)
    {
        Queue<String> strs = new ConcurrentLinkedQueue<>();

        for (int i = 0; i < 10; i++)
        {
            strs.offer("a" + i);  // add
            // 多线程环境下对队列的 add 最好用 offer
            // offer 能返回添加成功与否
            // 多线程环境下请使用 offer，peek，poll
        }

        System.out.println(strs);

        System.out.println(strs.size());

        System.out.println(strs.poll());
        System.out.println(strs.size());

        System.out.println(strs.peek());
        System.out.println(strs.size());

        // 双端队列 Deque
    }
}
