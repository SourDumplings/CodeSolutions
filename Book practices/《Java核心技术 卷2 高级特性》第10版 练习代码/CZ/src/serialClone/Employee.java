package serialClone;

import java.time.LocalDate;

/**
 * The familiar Employee class, redefined to extend the SerialCloneable class.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/23 17:35
 */
public class Employee extends SerialCloneable
{
    private String name;
    private double salary;
    private LocalDate hireDay;

    public Employee(String name, double salary, int year, int month, int day)
    {
        this.name = name;
        this.salary = salary;
        this.hireDay = LocalDate.of(year, month, day);
    }

    public String getName()
    {
        return name;
    }

    public double getSalary()
    {
        return salary;
    }

    public LocalDate getHireDay()
    {
        return hireDay;
    }

    /**
     * Raise the salary of this employee
     *
     * @param byPrecent
     */
    public void raiseSalary(double byPrecent)
    {
        double raise = salary * byPrecent / 100;
        salary += raise;
    }

    @Override
    public String toString()
    {
        return "Employee{" +
            "name='" + name + '\'' +
            ", salary=" + salary +
            ", hireDay=" + hireDay +
            '}';
    }
}
