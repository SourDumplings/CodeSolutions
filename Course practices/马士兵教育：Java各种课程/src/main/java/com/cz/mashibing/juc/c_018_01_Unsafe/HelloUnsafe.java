package com.cz.mashibing.juc.c_018_01_Unsafe;

/* Java 中的 CAS 都是在 Unsafe 类中完成的
这个类可以直接操纵 JVM 中的内存
使我们具备类似 C/C++ 写程序的能力
*/

import java.lang.reflect.Field;
import sun.misc.Unsafe;

public class HelloUnsafe
{
    static class M
    {
        private M()
        {
        }

        int i = 0;
    }

    public static void main(String[] args)
    {
        /* getUnsafe方法一般不能直接调用，抛出 SecurityException，
        Unsafe 一般都要通过反射才能拿来用
         因为 JDK 通常不让用 UnSafe 类*/
        // Unsafe unsafe = Unsafe.getUnsafe();
        final Field unsafeField;
        try
        {
            unsafeField = Unsafe.class.getDeclaredField("theUnsafe");
            unsafeField.setAccessible(true);
            Unsafe unsafe = (Unsafe) unsafeField.get(null);
            M m = (M) unsafe.allocateInstance(M.class);
            m.i = 9;
            System.out.println(m.i);
        }
        catch (NoSuchFieldException | InstantiationException | IllegalAccessException e)
        {
            e.printStackTrace();
        }
    }
}


