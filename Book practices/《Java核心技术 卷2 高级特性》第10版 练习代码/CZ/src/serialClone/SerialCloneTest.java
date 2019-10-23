package serialClone;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/23 17:40
 */
public class SerialCloneTest
{
    public static void main(String[] args) throws CloneNotSupportedException
    {
        Employee harry = new Employee("Harry Hacker", 35000, 1989, 10, 1);
        // clone harry
        Employee harry2 = (Employee) harry.clone();

        // mutate harry
        harry.raiseSalary(10);

        // now harry and the clone are different
        System.out.println(harry);
        System.out.println(harry2);
    }
}
