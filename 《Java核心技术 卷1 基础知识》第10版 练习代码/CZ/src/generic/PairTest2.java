package generic;

import javafx.util.Pair;

import java.time.LocalDate;

/**
 * @author CHANG Zheng
 * @title: Pair2Test
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/523:53
 */
public class PairTest2
{
    public static void main(String[] args)
    {
        LocalDate[] birthdays =
                {
                        LocalDate.of(1906, 12, 9),
                        LocalDate.of(1815, 12, 10),
                        LocalDate.of(1903, 12, 3),
                        LocalDate.of(1910, 6, 22)
                };
        Pair<LocalDate, LocalDate> mm = ArrayAlg.minmax(birthdays);
        System.out.println("min = " + mm.getKey() + ", max = " +
                mm.getValue());
    }

}
