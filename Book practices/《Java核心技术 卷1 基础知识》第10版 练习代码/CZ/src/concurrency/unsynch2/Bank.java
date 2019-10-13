package concurrency.unsynch2;

import java.util.Vector;

/**
 * A bank with a number of bank accounts.
 *
 * @author CHANG Zheng
 * @title: Bank
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1219:09
 */
public class Bank
{
    private final Vector<Double> accounts;

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
        accounts = new Vector<>(n);
        accounts.setSize(n);
        for (int i = 0; i < n; i++)
        {
            accounts.set(i, initialBalance);
        }
    }

    /**
     * Transfer money from one account to another.
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/12 19:16
     */
    public void transfer(int from, int to, double ammount)
    {
        if (accounts.get(from) < ammount)
        {
            return;
        }
        System.out.print(Thread.currentThread());
        accounts.set(from, accounts.get(from) - ammount);
        System.out.printf(" %10.2f from %d to %d", ammount, from, to);
        accounts.set(to, accounts.get(to) + ammount);
        System.out.printf(" Total Balance: %10.2f%n", getTotalBalance());

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
        return accounts.size();
    }
}
