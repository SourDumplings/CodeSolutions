package innnerClass.staticInnerClass;

import java.util.Arrays;

/**
 * @author CHANG Zheng
 * @title: StaticInnerClassTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/211:11
 */
public class StaticInnerClassTest
{
    public static void main(String[] args)
    {
        double[] d = new double[20];
        for (int i = 0; i < 20; i++)
        {
            d[i] = 100 * Math.random();
        }
        ArrayAlg.Pair p = ArrayAlg.minmax(d);
        System.out.println(Arrays.toString(d));
        System.out.println("min = " + p.getFirst());
        System.out.println("max = " + p.getSecond());
    }
}
