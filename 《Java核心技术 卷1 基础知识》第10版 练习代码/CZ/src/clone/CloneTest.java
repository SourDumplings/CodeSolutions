package clone;

import domain.Employee;

/**
 * @author Chang Zheng
 * @title: CloneTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2615:15
 */
public class CloneTest
{
    public static void main(String[] args)
    {
        Employee original = new Employee("John Q.Public", 50000);
        original.setHireDay(2000, 1, 1);
        Employee copy = null;

//        浅拷贝
//        Employee copy = original;
        // 深拷贝
        try
        {
            copy = original.clone();
        }
        catch (CloneNotSupportedException e)
        {
            e.printStackTrace();
        }

        copy.raiseSalary(10);
        copy.setHireDay(2002, 12, 31);
        System.out.println("original = " + original);
        System.out.println("copy = " + copy);

    }
}
