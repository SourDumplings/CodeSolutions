package com.cz.mashibing.juc.c_023_02_FromHashtableToCHM;

import java.util.Map;
import java.util.UUID;
import java.util.concurrent.ConcurrentHashMap;

public class T04_TestConcurrentHashMap
{

    static Map<UUID, UUID> m = new ConcurrentHashMap<>();

    static int count = Constants.COUNT;
    static UUID[] keys = new UUID[count];
    static UUID[] values = new UUID[count];
    static final int THREAD_COUNT = Constants.THREAD_COUNT;

    static
    {
        for (int i = 0; i < count; i++)
        {
            keys[i] = UUID.randomUUID();
            values[i] = UUID.randomUUID();
        }
    }

    static class MyThread extends Thread
    {
        int start;
        int gap = count / THREAD_COUNT;

        public MyThread(int start)
        {
            this.start = start;
        }

        @Override
        public void run()
        {
            for (int i = start; i < start + gap; i++)
            {
                m.put(keys[i], values[i]);
            }
        }
    }

    public static void main(String[] args)
    {

        long start = System.currentTimeMillis();

        Thread[] threads = new Thread[THREAD_COUNT];

        for (int i = 0; i < threads.length; i++)
        {
            threads[i] =
                new MyThread(i * (count / THREAD_COUNT));
        }

        for (Thread t : threads)
        {
            t.start();
        }

        for (Thread t : threads)
        {
            try
            {
                t.join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        long end = System.currentTimeMillis();
        System.out.println(end - start);

        System.out.println(m.size());

        /*
        输出：
        2114
        1000000
        1695
        如果只是插入元素的话
        ConcurrentHashMap 的效率不高，不如 Hashtable
        ConcurrentHashMap 的效率高在读上面
        因为 ConcurrentHashMap 检查了许多东西
        所以实际中哪个效率高要以实测为准
        * */
        //-----------------------------------

        start = System.currentTimeMillis();
        for (int i = 0; i < threads.length; i++)
        {
            threads[i] = new Thread(() ->
            {
                for (int j = 0; j < 10000000; j++)
                {
                    m.get(keys[10]);
                }
            });
        }

        for (Thread t : threads)
        {
            t.start();
        }

        for (Thread t : threads)
        {
            try
            {
                t.join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        end = System.currentTimeMillis();
        System.out.println(end - start);
    }
}
