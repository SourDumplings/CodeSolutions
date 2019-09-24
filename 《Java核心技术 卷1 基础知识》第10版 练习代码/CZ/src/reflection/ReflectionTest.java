package reflection;

import java.lang.reflect.*;
import java.util.*;

/**
 * @author Chang Zheng
 * @title: reflection.ReflectionTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2418:01
 * <p>
 * <p>
 * 输入：
 * java.lang.Double
 * 输出：
 * public final class java.lang.Double extends java.lang.Number
 * {
 * public java.lang.Double(double);
 * public java.lang.Double(java.lang.String);
 * <p>
 * public boolean equals(java.lang.Object);
 * public static java.lang.String toString(double);
 * public java.lang.String toString();
 * public int hashCode();
 * public static int hashCode(double);
 * public static double min(double, double);
 * public static double max(double, double);
 * public static native long doubleToRawLongBits(double);
 * public static long doubleToLongBits(double);
 * public static native double longBitsToDouble(long);
 * public volatile int compareTo(java.lang.Object);
 * public int compareTo(java.lang.Double);
 * public byte byteValue();
 * public short shortValue();
 * public int intValue();
 * public long longValue();
 * public float floatValue();
 * public double doubleValue();
 * public static java.lang.Double valueOf(java.lang.String);
 * public static java.lang.Double valueOf(double);
 * public static java.lang.String toHexString(double);
 * public static int compare(double, double);
 * public static boolean isNaN(double);
 * public boolean isNaN();
 * public static boolean isFinite(double);
 * public static boolean isInfinite(double);
 * public boolean isInfinite();
 * public static double sum(double, double);
 * public static double parseDouble(java.lang.String);
 * <p>
 * public static final double POSITIVE_INFINITY;
 * public static final double NEGATIVE_INFINITY;
 * public static final double NaN;
 * public static final double MAX_VALUE;
 * public static final double MIN_NORMAL;
 * public static final double MIN_VALUE;
 * public static final int MAX_EXPONENT;
 * public static final int MIN_EXPONENT;
 * public static final int SIZE;
 * public static final int BYTES;
 * public static final java.lang.Class TYPE;
 * private final double value;
 * private static final long serialVersionUID;
 * }
 */
public class ReflectionTest
{
    public static void main(String[] args)
    {
        // 从控制台读取输入的类名
        String name;
        if (args.length > 0)
        {
            name = args[0];
        }
        else
        {
            Scanner in = new Scanner(System.in);
            System.out.println("Enter class name (eg.) java.util.Date:");
            name = in.next();
        }

        try
        {
            // 打印类名和超类的名字
            Class cl = Class.forName(name);
            Class supercl = cl.getSuperclass();
            String modifiers = Modifier.toString(cl.getModifiers());
            if (modifiers.length() > 0)
            {
                System.out.print(modifiers + " ");
            }
            System.out.print("class " + name);
            if (supercl != null && supercl != Object.class)
            {
                System.out.print(" extends " + supercl.getName());
            }
            System.out.print("\n{\n");
            printConstructors(cl);
            System.out.println();
            printMethods(cl);
            System.out.println();
            printFields(cl);
            System.out.print("}");
        }
        catch (ClassNotFoundException e)
        {
            e.printStackTrace();
        }
        System.exit(0);
    }

    /**
     * 　　* @description: TODO 打印出类中的域变量
     * 　　* @param [cl]
     * 　　* @return void
     * 　　* @author Chang Zheng
     * 　　* @date 2019/9/24 18:46
     */
    private static void printFields(Class cl)
    {
        Field[] fields = cl.getDeclaredFields();

        for (Field f : fields)
        {
            Class type = f.getType();
            String name = f.getName();
            System.out.print("    ");
            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0)
            {
                System.out.print(modifiers + " ");
            }
            System.out.println(type.getName() + " " + name + ";");
        }
    }

    /**
     * 　　* @description: TODO 打印方法的方法
     * 　　* @param [cl]
     * 　　* @return void
     * 　　* @author Chang Zheng
     * 　　* @date 2019/9/24 18:31
     */
    private static void printMethods(Class cl)
    {
        Method[] methods = cl.getDeclaredMethods(); // 这个返回cl的所有方法（不包括从超类中继承的）
        for (Method m : methods)
        {
            Class retType = m.getReturnType();
            String name = m.getName();

            System.out.print("    ");
            // 打印标识符，返回类型和方法名
            String modifiers = Modifier.toString(m.getModifiers());
            if (modifiers.length() > 0)
            {
                System.out.print(modifiers + " ");
            }
            System.out.print(retType.getName() + " " + name + "(");

            // 打印参数类型列表
            Class[] paramTypes = m.getParameterTypes();
            int output = 0;
            for (Class p : paramTypes)
            {
                if (output++ > 0)
                {
                    System.out.print(", ");
                }
                System.out.print(p.getName());
            }
            System.out.println(");");
        }
    }

    /**
     * 　　* @description: TODO 打印所有的构造器的方法
     * 　　* @param [cl]
     * 　　* @return void
     * 　　* @author Chang Zheng
     * 　　* @date 2019/9/24 18:25
     */
    private static void printConstructors(Class cl)
    {
        Constructor[] constructors = cl.getDeclaredConstructors();
        for (Constructor c : constructors)
        {
            String name = c.getName();
            System.out.print("    ");
            String modifiers = Modifier.toString(c.getModifiers());
            if (modifiers.length() > 0)
            {
                System.out.print(modifiers + " ");
            }
            System.out.print(name + "(");

            // 打印参数类型列表
            Class[] paramTypes = c.getParameterTypes();
            int output = 0;
            for (Class cp : paramTypes)
            {
                if (output++ > 0)
                {
                    System.out.print(", ");
                }
                System.out.print(cp.getName());
            }
            System.out.println(");");
        }
    }
}
