package domain;

import java.io.Serializable;

/**
 * @author Chang Zheng
 * @title: Person
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2615:05
 */
public class Person implements Serializable
{
    private String name;
    public static final int NAME_SIZE = 40; // Employee的名字最多是40个字符，即80字节


    public Person(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    @Override
    public String toString()
    {
        return "Person[name = " + name + "]";
    }
}
