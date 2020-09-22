package com.cz.mashibing.juc.c_025;

import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class T06_ArrayBlockingQueue
{

    static BlockingQueue<String> strs = new ArrayBlockingQueue<>(10);

    static Random r = new Random();

    public static void main(String[] args) throws InterruptedException
    {
        for (int i = 0; i < 10; i++)
        {
            strs.put("a" + i);
        }

        //strs.put("aaa"); //满了就会等待，程序阻塞
        //strs.add("aaa"); // 满了会抛异常
        //strs.offer("aaa"); // 满了会返回 false，代表添加失败
        strs.offer("aaa", 1, TimeUnit.SECONDS); // 满了会等 1 s 再试一次

		/* 这里看出 Queue 相比于 List，添加了许多线程友好的接口，更适于多线程环境 */

        System.out.println(strs);
    }
}