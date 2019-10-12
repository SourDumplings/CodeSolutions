package generic;

import domain.Manager;

/**
 * @author CHANG Zheng
 * @title: Pair
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/913:36
 */
public class Pair<T>
{
    private T first;
    private T second;

    public Pair()
    {
        first = null;
        second = null;
    }

    public Pair(T first, T second)
    {
        this.first = first;
        this.second = second;
    }

    public T getFirst()
    {
        return first;
    }

    public void setFirst(T first)
    {
        this.first = first;
    }

    public T getSecond()
    {
        return second;
    }

    public void setSecond(T second)
    {
        this.second = second;
    }
}
