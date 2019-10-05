package stackTrace;

import java.util.Scanner;

/**
 * A program that display a trace feature of a recursive method call.
 * 输入：3
 * 输出：
 * factorial(3):
 * stackTrace.StackTraceTest.factorial(StackTraceTest.java:19)
 * stackTrace.StackTraceTest.main(StackTraceTest.java:43)
 * factorial(2):
 * stackTrace.StackTraceTest.factorial(StackTraceTest.java:19)
 * stackTrace.StackTraceTest.factorial(StackTraceTest.java:32)
 * stackTrace.StackTraceTest.main(StackTraceTest.java:43)
 * factorial(1):
 * stackTrace.StackTraceTest.factorial(StackTraceTest.java:19)
 * stackTrace.StackTraceTest.factorial(StackTraceTest.java:32)
 * stackTrace.StackTraceTest.factorial(StackTraceTest.java:32)
 * stackTrace.StackTraceTest.main(StackTraceTest.java:43)
 * return 1
 * return 2
 * return 6
 *
 * @author CHANG Zheng
 * @title: StackTraceTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/417:17
 */
public class StackTraceTest
{
    public static int factorial(int n)
    {
        System.out.println("factorial(" + n + "):");
        Throwable t = new Throwable();
        StackTraceElement[] frames = t.getStackTrace();
        for (StackTraceElement f : frames)
        {
            System.out.println(f);
        }
        int r;
        if (n <= 1)
        {
            r = 1;
        }
        else
        {
            r = n * factorial(n - 1);
        }
        System.out.println("return " + r);
        return r;
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter n: ");
        int n = in.nextInt();
        factorial(n);
    }
}
