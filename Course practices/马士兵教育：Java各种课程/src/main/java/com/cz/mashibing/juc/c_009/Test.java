package com.cz.mashibing.juc.c_009;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 马士兵教育：Java各种课程
 * @date 2020/8/24 18:15
 */

class F
{
    protected synchronized void m()
    {
        System.out.println("F.m");
    }

    static void n()
    {
        System.out.println("F.n");
    }
}

class C extends F
{
    /* 方法重写的三个条件
    1.方法名，参数列表相同
    2.返回值类型和声明异常类型，子类小于等于父类
    3.访问权限，子类大于等于父类*/
    @Override
    public synchronized void m()
    {
        super.m();
        System.out.println("C.m");
    }

/*
    private、static、final 的方法不能被重写
    @Override
    void n()
    {
        super.n();
    }*/
}

public class Test
{
    public static void main(String[] args)
    {
        C c = new C();
/*        c.m();
        输出为：
        F.m
        C.m
        证明了 synchronized 是可重入的，
        两个 synchronized 锁的都是同一个对象，同一把锁，见 C_10*/
    }
}
