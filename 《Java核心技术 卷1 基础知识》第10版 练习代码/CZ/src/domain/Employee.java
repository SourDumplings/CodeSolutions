package domain;

import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Objects;

/**
 * @author Chang Zheng
 * @title: Employee
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2615:05
 */
public class Employee extends Person implements Cloneable
{
    private double salary;
    private Date hireDay;

    public Employee(String name, double salary, Date hireDay)
    {
        super(name);
        this.salary = salary;
        this.hireDay = hireDay;
    }

    public Employee(String name, double salary)
    {
        super(name);
        this.salary = salary;
        this.hireDay = new Date();
    }

    public Employee clone() throws CloneNotSupportedException
    {
        Employee cloned = (Employee) super.clone();
        cloned.hireDay = (Date) hireDay.clone();
        return cloned;
    }

    public Date getHireDay()
    {
        return hireDay;
    }

    public void setHireDay(Date hireDay)
    {
        this.hireDay = hireDay;
    }

    public void setHireDay(int year, int month, int day)
    {
        this.hireDay = new GregorianCalendar(year, month - 1, day).getTime();
    }

    public double getSalary()
    {
        return salary;
    }

    public void setSalary(double salary)
    {
        this.salary = salary;
    }

    public void raiseSalary(double byPercent)
    {
        salary += salary * byPercent / 100;
    }

    @Override
    public String toString()
    {
        return "Employee[name = " + getName() + ", salary = " +
                getSalary() + ", hireDay = " + getHireDay() + "]";
    }

    @Override
    public boolean equals(Object otherObject)
    {
        if (this == otherObject)
        {
            return true;
        }

        if (otherObject == null)
        {
            return false;
        }

        if (getClass() != otherObject.getClass())
        {
            return false;
        }

        Employee other = (Employee) otherObject;

        return Objects.equals(getName(), other.getName()) && salary == other.salary
                && Objects.equals(hireDay, other.hireDay);

    }

    @Override
    public int hashCode()
    {
        return Objects.hash(getName(), salary, hireDay);
    }
}
