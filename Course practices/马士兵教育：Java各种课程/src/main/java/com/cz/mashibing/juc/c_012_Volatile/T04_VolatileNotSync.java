/**
 * volatile并不能保证多个线程共同修改running变量时所带来的不一致问题，也就是说volatile不能替代synchronized 运行下面的程序，并分析结果
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_012_Volatile;

import java.util.ArrayList;
import java.util.List;

public class T04_VolatileNotSync
{
    volatile int count = 0;

    void m()
    {
		for (int i = 0; i < 10000; i++)
		{
			count++;
		}
    }

    public static void main(String[] args)
    {
        T04_VolatileNotSync t = new T04_VolatileNotSync();

        List<Thread> threads = new ArrayList<Thread>();

        for (int i = 0; i < 10; i++)
        {
            threads.add(new Thread(t::m, "thread-" + i));
        }

        threads.forEach((o) -> o.start());

        threads.forEach((o) ->
        {
            try
            {
                o.join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        });

        System.out.println(t.count);


    }

    /* volatile 不保证原子性
    count++ 不是原子操作，实际上会分成许多条指令
    所以输出的值不正确
    * */

}