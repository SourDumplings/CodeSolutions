/**
 * 软引用
 * 软引用是用来描述一些还有用但并非必须的对象。
 * 对于软引用关联着的对象，在系统将要发生内存溢出异常之前，将会把这些对象列进回收范围进行第二次回收。
 * 如果这次回收还没有足够的内存，才会抛出内存溢出异常。
 * 测试该程序需要设置 VM 选项，-Xms20M -Xmx20M 即只分配 20 M 的堆内存
 */
package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

import java.lang.ref.SoftReference;

public class T02_SoftReference
{
    public static void main(String[] args)
    {
        SoftReference<byte[]> m = new SoftReference<>(new byte[1024 * 1024 * 10]);  /* 10 MB 大小的数组*/
        //m = null;
        System.out.println(m.get());
        System.gc(); // full gc
        try
        {
            Thread.sleep(500);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        /* 虽然调了 gc，但是内存够用，软引用指向的对象没有被回收掉 */
        System.out.println(m.get());

        //再分配一个数组，heap将装不下，这时候系统会垃圾回收，先回收一次，如果不够，会把软引用干掉
        byte[] b = new byte[1024 * 1024 * 15]; // 15 M 的字节数组，此时堆内存已经不够用了
        // 只有软引用指向的对象就被回收了
        System.out.println(m.get());

/*        输出结果：
        [B @ 2812 cbfa
        [B @ 2812 cbfa
        null*/
    }
}

// 软引用非常适合缓存使用，只有系统不够用了才会回收只有软引用指向的对象
// 实际中缓存用 Redis
