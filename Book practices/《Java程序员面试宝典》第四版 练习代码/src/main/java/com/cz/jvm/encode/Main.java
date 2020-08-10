package com.cz.jvm.encode;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java程序员面试宝典》第四版 练习代码
 * @date 2020/8/10 14:09
 */
public class Main
{
    public static void main(String[] args)
    {
        char han = '永';
        System.out.println(han);
        System.out.printf("%x\n", (short) han);
        char hex = 0x6c38;
        System.out.println(hex);
       /* 输出为：
        永
        6c38
        永
       * */
    }
}
