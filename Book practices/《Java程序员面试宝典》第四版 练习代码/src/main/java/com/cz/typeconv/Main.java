package com.cz.typeconv;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java程序员面试宝典》第四版 练习代码
 * @date 2020/8/10 16:03
 */
public class Main
{
    public static void main(String[] args)
    {
        // Short myshort = 99S;
        Short myshort = (short) 99;
        int t = "abc".length();
        // float z = 1.0;
        float z = 1.0f;
        // char c = 17c;
        char c = 17;

        float f1 = 100.00f;
        Float F1 = new Float(f1);
        Double D1 = F1.doubleValue();

        String fs1 = "100.0";
        Float FS1 = Float.parseFloat(fs1);
        System.out.println("FS1: " + FS1);

        short s = 1;
        s += 1;
        // s = s +1; 错误，s + 1 为 int，不能直接赋值给 short.
        s = (short) (s + 1);
    }
}
