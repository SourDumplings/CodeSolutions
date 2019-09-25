package reflection.objectAnalyzer;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Chang Zheng
 * @title: ObjectAnalyzerTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2515:21
 */
public class ObjectAnalyzerTest
{
    public static void main(String[] args)
    {
        List<Integer> squares = new ArrayList<>();
        for (int i = 0; i < 6; ++i)
        {
            squares.add(i * i);
        }
        System.out.println(new ObjectAnalyzer().toString(squares));

        System.out.println("-------------------------------------");
        A a = new A();
        System.out.println(new ObjectAnalyzer().toString(a));
    }
}

class A
{
    private Integer i;
    protected String name;
    public double d;
    public A()
    {
        i = 10;
        d = 8.8;
        name = "aaa";
    }
}
