package proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

/**
 * An invocation handler that prints out the method name and parameters,
 * then invokes the original method
 *
 * @author CHANG Zheng
 * @title: TraceHandler
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/213:07
 */
public class TraceHandler implements InvocationHandler
{
    private Object target;

    public TraceHandler(Object t)
    {
        this.target = t;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable
    {
        // print implicit argument
        System.out.print(target);
        // print method name
        System.out.print("." + method.getName() + "(");
        // print explicit arguments
        if (args != null)
        {
            int output = 0;
            for (Object arg : args)
            {
                if (output++ != 0)
                {
                    System.out.println(", ");
                }
                System.out.print(arg);
            }
        }
        System.out.println(")");
        // invoke actual method
        return method.invoke(target, args);
    }
}
