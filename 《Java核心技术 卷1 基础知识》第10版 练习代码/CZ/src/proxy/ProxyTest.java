package proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Proxy;
import java.util.Arrays;
import java.util.Random;

/**
 * This program demonstrates the use of proxies
 * 跟踪方法调用
 *
 * @author CHANG Zheng
 * @title: ProxyTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/213:12
 */
public class ProxyTest
{
    public static void main(String[] args)
    {
        Object[] elements = new Object[1000];

        // fill elements with proxies for the integers 1, 2, ..., 1000
        for (int i = 0; i < 1000; i++)
        {
            Integer value = i + 1;
            InvocationHandler handler = new TraceHandler(value);
            Object proxy = Proxy.newProxyInstance(null, new Class[]{Comparable.class}, handler);
            elements[i] = proxy;
        }
        // construct a random integer
        Integer key = new Random().nextInt(elements.length) + 1;
        // search for the key
        int result = Arrays.binarySearch(elements, key);
        // print match if found
        if (result >= 0)
        {
            System.out.println(elements[result]);
        }
    }
}
