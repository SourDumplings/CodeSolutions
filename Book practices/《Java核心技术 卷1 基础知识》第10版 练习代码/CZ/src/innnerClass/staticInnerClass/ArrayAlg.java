package innnerClass.staticInnerClass;

/**
 * 同时选出数组最大值和最小值的类
 *
 * @author CHANG Zheng
 * @title: ArrayAlg
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/210:56
 */
public class ArrayAlg
{
    /**
     * A pair of floating-point numbers
     */
    public static class Pair
    {
        private double first;
        private double second;

        public Pair(double first, double second)
        {
            this.first = first;
            this.second = second;
        }

        public double getFirst()
        {
            return first;
        }

        public void setFirst(double first)
        {
            this.first = first;
        }

        public double getSecond()
        {
            return second;
        }

        public void setSecond(double second)
        {
            this.second = second;
        }
    }

    /**
     * Computes both the minimum and maximum of an array
     *
     * @param
     * @return innnerClass.staticInnerClass.ArrayAlg.Pair
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/2 11:04
     */
    public static Pair minmax(double[] values)
    {
        double min = Double.MAX_VALUE;
        double max = Double.MIN_VALUE;
        for (double i : values)
        {
            if (i < min)
            {
                min = i;
            }
            if (i > max)
            {
                max = i;
            }
        }
        return new Pair(min, max);
    }
}
