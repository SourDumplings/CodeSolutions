package concurrency.synch3;

import java.util.Arrays;
import java.util.Objects;

/**
 * A bank with a number of bank accounts that uses synchronization methods.
 *
 * @author CHANG Zheng
 * @title: Bank
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1219:09
 */
public class Bank
{
    private final double[] accounts;
    private final Object lock;

    /**
     * Constructs the bank.
     *
     * @param n the number of accounts
     * @return
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/12 19:14
     */
    public Bank(int n, double initialBalance)
    {
        accounts = new double[n];
        lock = new Object();
        Arrays.fill(accounts, initialBalance);
    }

    /**
     * Transfer money from one account to another.
     * Protected by ReentrantLock.
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/12 19:16
     */
    public void transfer(int from, int to, double ammount) throws InterruptedException
    {
        if (accounts[from] < ammount)
        {
            return;
        }
        synchronized (lock)
        {
            while (accounts[from] < ammount)
            {
                lock.wait();
            }
            System.out.print(Thread.currentThread());
            accounts[from] -= ammount;
            System.out.printf(" %10.2f from %d to %d", ammount, from, to);
            accounts[to] += ammount;
            System.out.printf(" Total Balance: %10.2f%n", getTotalBalance());
            lock.notifyAll();
        }
    }

    /**
     * Gets the sum of all account balances.
     *
     * @param
     * @return double
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/12 19:20
     */
    public double getTotalBalance()
    {
        double sum = 0;

        synchronized (lock)
        {
            for (double account : accounts)
            {
                sum += account;
            }
        }
        return sum;
    }

    /**
     * Gets the number of accounts in the bank.
     *
     * @param
     * @return int
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/12 19:20
     */
    public int size()
    {
        return accounts.length;
    }
}
