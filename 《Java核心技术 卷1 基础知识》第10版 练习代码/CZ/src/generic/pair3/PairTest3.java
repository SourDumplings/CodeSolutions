package generic.pair3;

import domain.Employee;
import domain.Manager;
import generic.Pair;

import java.util.Date;

/**
 * @author CHANG Zheng
 * @title: PairTest3
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/913:41
 */
public class PairTest3
{
    public static void main(String[] args)
    {
        Manager ceo = new Manager("Stupid Pig", 800000, new Date(2003, 12, 15));
        Manager cfo = new Manager("Smart Cat", 600000, new Date(2003, 12, 15));
        Pair<Manager> buddies = new Pair<>(ceo, cfo);
        printBuddies(buddies);

        ceo.setBonus(1000000);
        cfo.setBonus(500000);
        Manager[] managers = {ceo, cfo};

        Pair<Employee> result = new Pair<>();
        minmaxBonus(managers, result);
        System.out.println("first: " + result.getFirst().getName() + ", second: " + result.getSecond().getName());
        maxminBonus(managers, result);
        System.out.println("first: " + result.getFirst().getName() + ", second: " + result.getSecond().getName());
    }

    public static void printBuddies(Pair<? extends Employee> p)
    {
        Employee first = p.getFirst();
        Employee second = p.getSecond();
        System.out.println(first.getName() + " and " + second.getName() + " are buddies.");
    }

    public static void minmaxBonus(Manager[] a, Pair<? super Manager> result)
    {
        if (a.length == 0)
        {
            return;
        }

        Manager min = a[0];
        Manager max = a[0];
        for (Manager m : a)
        {
            if (m.getBonus() < min.getBonus())
            {
                min = m;
            }
            if (m.getBonus() > max.getBonus())
            {
                max = m;
            }
        }
        result.setFirst(min);
        result.setSecond(max);
    }

    public static void maxminBonus(Manager[] a, Pair<? super Manager> result)
    {
        minmaxBonus(a, result);
        PairAlg.swap(result);
    }
}
