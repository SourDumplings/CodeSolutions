package concurrency.forkJoin;

import java.util.concurrent.ForkJoinPool;

/**
 * This program demonstrates the fork-join framework.
 * 计算数组里大于0.5的元素个数。
 *
 * @author CHANG Zheng
 * @title: ForkJoinTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1417:45
 */
public class ForkJoinTest
{
    public static void main(String[] args)
    {
        final int SIZE = 10000000;
        double[] numbers = new double[SIZE];
        for (int i = 0; i < numbers.length; i++)
        {
            numbers[i] = Math.random();
        }
        Counter counter = new Counter(numbers, 0, numbers.length, x -> x > 0.5);
        ForkJoinPool pool = new ForkJoinPool();
        pool.invoke(counter);
        System.out.println(counter.join());
    }
}
