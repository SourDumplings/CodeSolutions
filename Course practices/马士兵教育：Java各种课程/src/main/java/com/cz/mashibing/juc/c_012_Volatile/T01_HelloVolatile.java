/**
 * volatile 关键字，使一个变量在多个线程间可见 A B线程都用到一个变量，java默认是A线程中保留一份copy，这样如果B线程修改了该变量，则A线程未必知道
 * 使用volatile关键字，会让所有线程都会读到变量的修改值
 * <p>
 * 在下面的代码中，running是存在于堆内存的t对象中 当线程t1开始运行的时候，会把running值从内存中读到t1线程的工作区，在运行过程中直接使用这个copy，并不会每次都去
 * 读取堆内存，这样，当主线程修改running的值之后，t1线程感知不到，所以不会停止运行
 * <p>
 * 使用volatile，将会强制所有线程都去堆内存中读取running的值
 * <p>
 * 可以阅读这篇文章进行更深入的理解 http://www.cnblogs.com/nexiyi/p/java_memory_model_and_thread.html
 * <p>
 * volatile并不能保证多个线程共同修改running变量时所带来的不一致问题，也就是说volatile不能替代synchronized
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_012_Volatile;

import java.util.concurrent.TimeUnit;

public class T01_HelloVolatile
{
    /*volatile*/ boolean running = true; //对比一下有无volatile的情况下，整个程序运行结果的区别

    void m()
    {
        System.out.println("m start");
        while (running)
        {
        }
        System.out.println("m end!");
    }

    public static void main(String[] args)
    {
        T01_HelloVolatile t = new T01_HelloVolatile();

        new Thread(t::m, "t1").start();

        try
        {
            TimeUnit.SECONDS.sleep(1);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        t.running = false;

        /*
        * 运行结果是：
        * 如果没有加 volatile，则只输出 m start，t1 线程不会停止
        * 加了 volatile 之后，就会正常的在输出 m start 一秒钟之后输出 m end，t1 线程停止
        * volatile 有两个作用：
        * 1.保证线程可见性
        * 	由 CPU 的 MESI 缓存一致性协议保证
        * 2.禁止指令重排序
        *
        * 对比于 synchronized 关键字，synchronized 关键字是用来保证原子性，不能阻止指令重排序
        *
        * JVM 对于 new 语句的处理分成三步：申请内存、成员变量的初始化、赋值给引用，见 TestNew
        * 如果出现指令重排序可能会将未初始化完全的对象赋值给引用（一般只有超高并发时才会出现），
        * 可以加 volatile 防止这种问题
        *
        * 在没有 volatile 时 running 变量在主线程工作内存中的副本被修改了，
        * 但是没有及时同步到 t1 线程的工作内存中去，即 t1 没有及时看到这个改变
        * 如果加了 volatile，t1 线程就能及时看到了，即 volatile 使得线程不缓存变量 running
        *
        * */
    }

}