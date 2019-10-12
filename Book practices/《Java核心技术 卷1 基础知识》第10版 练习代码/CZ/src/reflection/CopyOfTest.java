package reflection;

import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * @author Chang Zheng
 * @title: CopyOfTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2516:07
 */
public class CopyOfTest
{
    public static void main(String[] args)
    {
        int[] a = {1, 2, 3};
        a = (int[]) goodCopyOf(a, 10);
        System.out.println(Arrays.toString(a));

        String[] b = {"Tom", "Jerry", "Hello"};
        b = (String[]) goodCopyOf(b, 10);
        System.out.println(Arrays.toString(b));
    }

    /**
     * 　　* @description: TODO 通过数组的拷贝实现数组的动态扩容
     * 　　* @param [a, newLength]
     * 　　* @return java.lang.Object
     * 　　* @author Chang Zheng
     * 　　* @date 2019/9/25 16:08
     */
    public static Object goodCopyOf(Object a, int newLength)
    {
        Class cl = a.getClass();
        if (!cl.isArray())
        {
            return null;
        }
        Class componentType = cl.getComponentType();
        int l = Array.getLength(a);
        Object newArray = Array.newInstance(componentType, newLength);
        System.arraycopy(a, 0, newArray, 0, Math.min(l, newLength));
        return newArray;

    }
}
