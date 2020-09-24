package com.cz.mashibing.juc.c_025;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.SynchronousQueue;

public class T08_SynchronusQueue
{ //容量为0
    /* 这个类用于一个线程给另一个线程下达任务的，不是用来装元素的
     * 类似于 Exchanger */
    public static void main(String[] args) throws InterruptedException
    {
        BlockingQueue<String> strs = new SynchronousQueue<>();

        new Thread(() ->
        {
            try
            {
                System.out.println(strs.take());
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }).start();

        strs.put("aaa"); // 如果没有消费者线程，就会阻塞等待消费者消费
        //strs.put("bbb");
        //strs.add("aaa"); // 会报错，SynchronusQueue 不能用来装元素
        System.out.println(strs.size());
    }
}