package com.cz.operator;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java程序员面试宝典》第四版 练习代码
 * @date 2020/8/19 21:41
 */
public class Main
{
    public static void main(String[] args)
    {
        // 输出为 9.0
        // 由于 10.9 的存在，9 会自动类型转换为 double 类型 9.0
        int a = 5;
        System.out.println((a < 5) ? 10.9 : 9);

        // 输出为 120 x
        char x = 'x';
        int i = 0;
        // 这里由于 i 是 int 型，i 是一个变量，故会导致 x 被提升为 int 型
        System.out.println(false ? i : x);
        // Java 编程规范中提到，当后两个表达式中其中一个为常量表达式，另一个为类型 T 的变量，
        // 如果常量表达式能够被 T 表示时，输出结果为 T 类型
        // 这里由于 10 是常量，可以被 char 表示，故输出为 x
        System.out.println(false ? 10 : x);


    }
}
