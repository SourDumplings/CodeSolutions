package generic;

import javafx.util.Pair;

/**
 * @author CHANG Zheng
 * @title: Pair2
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/523:47
 */
public class ArrayAlg
{
    /**
     * 返回数组的最大最小值
     *
     * @param
     * @return javafx.util.Pair
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/5 23:49
     */
    public static <T extends Comparable> Pair<T, T> minmax(T a[])
    {
        if (a == null || a.length == 0)
        {
            return null;
        }
        T min = a[0];
        T max = a[0];
        for (T e : a)
        {
            if (min.compareTo(e) > 0)
            {
                min = e;
            }
            if (max.compareTo(e) < 0)
            {
                max = e;
            }
        }
        return new Pair<>(min, max);
    }
}
