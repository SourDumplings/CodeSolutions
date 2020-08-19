package com.cz.exception;

import java.io.IOException;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java程序员面试宝典》第四版 练习代码
 * @date 2020/8/19 22:15
 */
public class Main
{
    public static void main(String[] args) throws Exception
    {
        // finally 无论如何都会执行
        // test1();

        StringBuilder sb1 = new StringBuilder("a");
        StringBuilder sb2 = new StringBuilder("b");
        int i3 = 0;
        int i4 = 0;
        test2(sb1, sb2, i3, i4);
        // 输出为：
        // a1
        // b1
        // 0
        // 0
        System.out.println(sb1.toString());
        System.out.println(sb2.toString());
        System.out.println(i3);
        System.out.println(i4);
    }

    private static void test1() throws Exception
    {
        try
        {
            // throw new RuntimeException();
            throw new IOException();
        }
        catch (RuntimeException e)
        {
            System.out.println(1);
            return;
        }
        finally
        {
            System.out.println(2);
        }
    }

    private static void test2(StringBuilder sb1, final StringBuilder sb2, int i3, final int i4)
    {
        sb1.append(1);
        sb1 = null; // 函数内部改变引用不影响外部

        // sb2 = null; // final 使得引用不能变，但对象会通过方法而改变，类似于 C++ 中的 top const
        sb2.append(1);

        i3 = 1; // 对于基本类型是值传递，final 意义不大，不会影响外部
        // i4 = 1;
    }
}
