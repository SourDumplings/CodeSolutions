package com.cz.ipp;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java程序员面试宝典》第四版 练习代码
 * @date 2020/8/10 15:40
 */
public class Main
{
    public static void main(String[] args)
    {
        int j = 0;
        for (int i = 0; i < 100; i++)
        {
            j = j++;
        }
        System.out.println(j);
        // 输出0
    }
}
