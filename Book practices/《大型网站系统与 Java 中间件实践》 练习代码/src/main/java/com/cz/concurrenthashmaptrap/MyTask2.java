package com.cz.concurrenthashmaptrap;

import java.util.Map;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/24 17:42
 */
public class MyTask2 implements Runnable
{
    private String key;
    private Map map;

    public MyTask2(String key, Map map)
    {
        this.key = key;
        this.map = map;
    }

    @Override
    public void run()
    {
        synchronized (map)
        {
            map.put(key, (Integer) map.getOrDefault(key, 0) + 1);
        }
    }
}
