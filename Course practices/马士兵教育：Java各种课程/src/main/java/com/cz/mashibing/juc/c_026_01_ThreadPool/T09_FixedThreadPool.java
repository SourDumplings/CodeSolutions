/**
 * 任务来的速率比较平稳，用 FixedThreadPool 比较好
 *
 * 线程池中线程数过少，会导致 CPU 资源没有被有效利用，反之会导致 CPU 将资源都用在了线程切换上了
 * 线程池的较适大小一般用如下公式：
 * N = CPU 核心数 * 期望的 CPU 的利用率 * (1 + CPU 等待时间与计算时间比)
 * 但实际中要进行压测才能确定
 * 一般来说 IO 密集型的 CPU 等待时间与计算时间比高，计算密集型低
 */
package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class T09_FixedThreadPool
{
    public static void main(String[] args) throws InterruptedException, ExecutionException
    {
        long start = System.currentTimeMillis();
        getPrime(1, 200000);
        long end = System.currentTimeMillis();
        System.out.println(end - start);

        final int cpuCoreNum = 4;

        ExecutorService service = Executors.newFixedThreadPool(cpuCoreNum);

        MyTask t1 = new MyTask(1, 80000); //1-5 5-10 10-15 15-20
        MyTask t2 = new MyTask(80001, 130000);
        MyTask t3 = new MyTask(130001, 170000);
        MyTask t4 = new MyTask(170001, 200000);

        Future<List<Integer>> f1 = service.submit(t1);
        Future<List<Integer>> f2 = service.submit(t2);
        Future<List<Integer>> f3 = service.submit(t3);
        Future<List<Integer>> f4 = service.submit(t4);

        start = System.currentTimeMillis();
        f1.get();
        f2.get();
        f3.get();
        f4.get();
        end = System.currentTimeMillis();
        System.out.println(end - start);
    }

    static class MyTask implements Callable<List<Integer>>
    {
        int startPos, endPos;

        MyTask(int s, int e)
        {
            this.startPos = s;
            this.endPos = e;
        }

        @Override
        public List<Integer> call() throws Exception
        {
            List<Integer> r = getPrime(startPos, endPos);
            return r;
        }

    }

    static boolean isPrime(int num)
    {
        for (int i = 2; i <= num / 2; i++)
        {
			if (num % i == 0)
			{
				return false;
			}
        }
        return true;
    }

    static List<Integer> getPrime(int start, int end)
    {
        List<Integer> results = new ArrayList<>();
        for (int i = start; i <= end; i++)
        {
			if (isPrime(i))
			{
				results.add(i);
			}
        }

        return results;
    }
}
