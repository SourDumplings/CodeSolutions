package lambda;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author Chang Zheng
 * @title: TestLambda
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2618:11
 */
public class TestLambda
{
    public static void main(String[] args)
    {
        String[] strings = {"yes", "hello", "hi", "love you", "I"};
        // 使用方法引用
        Arrays.sort(strings, Comparator.comparingInt(String::length));
        // 使用lambda表达式
/*        Arrays.sort(strings, (first, second) ->
        {
            return first.length() - second.length();
        });*/
        System.out.println(Arrays.toString(strings));
    }
}
