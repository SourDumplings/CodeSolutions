package concurrency.synch2;

import java.util.Arrays;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * A bank with a number of bank accounts that uses synchronization primitives.
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
    public synchronized void transfer(int from, int to, double ammount) throws InterruptedException
    {
        if (accounts[from] < ammount)
        {
            return;
        }

        while (accounts[from] < ammount)
        {
            wait();
        }
        System.out.print(Thread.currentThread());
        accounts[from] -= ammount;
        System.out.printf(" %10.2f from %d to %d", ammount, from, to);
        accounts[to] += ammount;
        System.out.printf(" Total Balance: %10.2f%n", getTotalBalance());
        notifyAll();

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
    public synchronized double getTotalBalance()
    {
        double sum = 0;

        for (double account : accounts)
        {
            sum += account;
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
