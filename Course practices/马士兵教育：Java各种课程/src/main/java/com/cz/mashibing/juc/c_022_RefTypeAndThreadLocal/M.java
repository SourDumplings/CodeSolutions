package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

public class M
{
    @Override
    protected void finalize() throws Throwable
    {
        /* 一个对象被垃圾回收的时候会调用 finalize 方法
        这里重写这个方法的目的是为了看什么时候被 gc
        * */
        System.out.println("finalize");
    }
}
