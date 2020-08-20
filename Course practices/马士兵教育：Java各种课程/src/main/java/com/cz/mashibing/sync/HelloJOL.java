package com.cz.mashibing.sync;

import java.util.concurrent.TimeUnit;
import org.openjdk.jol.info.ClassLayout;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 马士兵教育：Java各种课程
 * @date 2020/8/17 17:07
 */
public class HelloJOL
{
    public static void main(String[] args) throws InterruptedException
    {
        // TimeUnit.SECONDS.sleep(5);
        Object o = new Object();
        System.out.println(ClassLayout.parseInstance(o).toPrintable());
        synchronized (o)
        {
            // synchronized 修改了 markward
            // markward 里面装了锁信息
            System.out.println(ClassLayout.parseInstance(o).toPrintable());
            // Java 1.6 之前 synchronized 是重量级锁，之后是轻量级锁
            // （用户态管理，内部存在锁升级过程，引入偏向锁，实在不行才会升级成重量级锁由 OS 管理）
        }
    }
}
