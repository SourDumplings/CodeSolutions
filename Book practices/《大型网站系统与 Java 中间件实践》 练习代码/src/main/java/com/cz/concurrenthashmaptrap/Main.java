package com.cz.concurrenthashmaptrap;

import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map.Entry;
import java.util.concurrent.ConcurrentHashMap;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/24 16:55
 */
public class Main
{
    private static ConcurrentHashMap<String, Integer> concurrentHashMap = new ConcurrentHashMap<>();
    private static HashMap<String, Integer> hashMap = new HashMap<>();
    private static Hashtable<String, Integer> hashtable = new Hashtable<>();

    private static String[] array = {"yy", "yy", "welcome", "java", "234", "java", "1234", "yy",
        "welcome", "yy", "java", "234", "yy"};

    public static void main(String[] args)
    {
        System.out.println("array size: " + array.length);
        for (String s : array)
        {
            // final Runnable myTask1 = new MyTask1(s, concurrentHashMap);
            // final Runnable myTask2 = new MyTask2(s, hashMap);
            final Runnable myTask11 = new MyTask1(s, hashtable);
            // new Thread(myTask1).start();
            // new Thread(myTask2).start();
            new Thread(myTask11).start();
        }

        // System.out.println("Results for using ConcurrentHashMap:");
        // for (Entry<String, Integer> stringIntegerEntry : concurrentHashMap.entrySet())
        // {
        //     System.out.println(stringIntegerEntry.getKey() + " : " + stringIntegerEntry.getValue());
        // }

        /* 输出会出现错误情况，说明线程不安全：
        array size: 13
        Results for using ConcurrentHashMap:
        yy : 4
        java : 3
        234 : 2
        1234 : 1
        welcome : 2*/

        // System.out.println("Results for using HashMap with lock");
        // for (Entry<String, Integer> stringIntegerEntry : hashMap.entrySet())
        // {
        //     System.out.println(stringIntegerEntry.getKey() + " : " + stringIntegerEntry.getValue());
        // }

        /* 输出始终正确，说明线程安全：
        array size: 13
        Results for using HashMap with lock
        yy : 5
        java : 3
        234 : 2
        1234 : 1
        welcome : 2
        * */


        System.out.println("Results for using Hashtable");
        for (Entry<String, Integer> stringIntegerEntry : hashtable.entrySet())
        {
            System.out.println(stringIntegerEntry.getKey() + " : " + stringIntegerEntry.getValue());
        }

        /* 输出会出现错误情况，说明线程不安全：
        array size: 13
        Results for using Hashtable
        234 : 2
        java : 3
        welcome : 2
        1234 : 1
        yy : 4*/
    }
}
