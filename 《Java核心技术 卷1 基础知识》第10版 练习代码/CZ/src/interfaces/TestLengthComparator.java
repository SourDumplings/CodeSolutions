package interfaces;

import java.util.Arrays;

/**
 * @author Chang Zheng
 * @title: TestLengthComparator
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2613:36
 */
public class TestLengthComparator
{
    public static void main(String[] args)
    {
        String[] strings = {"yes", "hello", "hi", "love you", "I"};
        LengthComparator lengthComparator = new LengthComparator();
        Arrays.sort(strings, lengthComparator);
        System.out.println(Arrays.toString(strings));
    }
}
