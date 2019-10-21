package domain;

import java.time.LocalDate;

/**
 * @author CHANG Zheng
 * @title: Manager
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/913:44
 */
public class Manager extends Employee
{
    private double bonus;


    public Manager(String name, double salary, LocalDate hireDay)
    {
        super(name, salary, hireDay);
        bonus = 0;
    }

    @Override
    public double getSalary()
    {
        double baseSalary = super.getSalary();
        return baseSalary + bonus;
    }

    public void setBonus(double bonus)
    {
        this.bonus = bonus;
    }

    @Override
    public boolean equals(Object otherObject)
    {
        if (!super.equals(otherObject))
        {
            return false;
        }

        Manager other = (Manager) otherObject;
        return bonus == other.bonus;
    }

    @Override
    public int hashCode()
    {
        return super.hashCode() + 17 * new Double(bonus).hashCode();
    }

    @Override
    public String toString()
    {
        return super.toString() + "[bonus=" + bonus + "]";
    }

    public double getBonus()
    {
        return bonus;
    }
}
