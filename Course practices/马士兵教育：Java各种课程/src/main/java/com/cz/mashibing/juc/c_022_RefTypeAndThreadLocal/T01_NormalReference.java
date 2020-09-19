package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

import java.io.IOException;

public class T01_NormalReference
{
    public static void main(String[] args) throws IOException
    {
        /* gc 是不会回收普通引用（强引用）指向的对象的 */
        M m = new M();
        m = null;
        System.gc(); //DisableExplicitGC

        System.in.read(); /* 阻塞住当前线程，gc 是跑在别的线程的 */
    }
}
