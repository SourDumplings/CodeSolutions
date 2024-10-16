package concurrency.synch;

import java.util.Arrays;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * A bank with a number of bank accounts that uses locks for serializing access.
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
    private Lock bankLock;
    private Condition sufficientFunds;

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
        bankLock = new ReentrantLock();
        sufficientFunds = bankLock.newCondition();
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
        bankLock.lock();
        try
        {
            while (accounts[from] < ammount)
            {
                sufficientFunds.await();
            }
            System.out.print(Thread.currentThread());
            accounts[from] -= ammount;
            System.out.printf(" %10.2f from %d to %d", ammount, from, to);
            accounts[to] += ammount;
            System.out.printf(" Total Balance: %10.2f%n", getTotalBalance());
            sufficientFunds.signalAll();
        }
        finally
        {
            bankLock.unlock();
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
        bankLock.lock();
        try
        {
            double sum = 0;

            for (double account : accounts)
            {
                sum += account;
            }
            return sum;
        }
        finally
        {
            bankLock.unlock();
        }
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
