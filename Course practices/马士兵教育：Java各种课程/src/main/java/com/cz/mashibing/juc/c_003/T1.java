/**
 * synchronized 关键字 对某个对象加锁
 *
 * @author mashibing
 */

package com.cz.mashibing.juc.c_003;

public class T1
{

    private int count = 10;

    public synchronized void m()
    { // 等同于在方法的代码执行时要 synchronized(this)
        count--;
        System.out.println(Thread.currentThread().getName() + " count = " + count);
    }

    public void n()
    { //�������������ʱ����Ҫ����
        count++;
    }
}
