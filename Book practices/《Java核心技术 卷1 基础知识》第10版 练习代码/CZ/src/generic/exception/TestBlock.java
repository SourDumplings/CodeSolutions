package generic.exception;

import java.io.File;
import java.util.Scanner;

/**
 * 测试利用泛型使得编译器忽略受查异常
 * 运行这个程序时，会得到一个栈轨迹，其中包含一个异常FileNotFoundException
 * 因为你没有提供一个ququx文件
 *
 * @author CHANG Zheng
 * @title: Test
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/718:52
 */
public class TestBlock
{
    public static void main(String[] args)
    {
        new Block()
        {
            @Override
            public void body() throws Exception
            {
                Scanner in = new Scanner(new File("ququx"), "utf-8");
                while (in.hasNext())
                {
                    System.out.println(in.next());
                }
            }
        }.toThread().start();
    }
}
