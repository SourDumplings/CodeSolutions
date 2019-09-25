package reflection.objectAnalyzer;

import java.lang.reflect.AccessibleObject;
import java.lang.reflect.Array;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.ArrayList;

/**
 * @author Chang Zheng
 * @title: ObjectAnalyzer
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO 通用的分析对象方法，将任意对象都转为字符串
 * @date 2019/9/2514:53
 */
public class ObjectAnalyzer
{
    // 记录访问过的对象，防止出现循环引用
    private ArrayList<Object> visited = new ArrayList<>();

    /**
     * 　　* @description: TODO
     * 　　* @param [obj]
     * 　　* @return java.lang.String
     * 　　* @author Chang Zheng
     * 　　* @date 2019/9/25 14:58
     */
    public String toString(Object obj)
    {
        if (obj == null)
        {
            return null;
        }
        if (visited.contains(obj))
        {
            return "...";
        }
        visited.add(obj);
        Class cl = obj.getClass();

        // 如果是数组类型
        if (cl.isArray())
        {
            StringBuilder sb = new StringBuilder();
            sb.append(cl.getComponentType());
            sb.append("[]{\n");
            int output = 0;
            int l = Array.getLength(obj);
            for (int i = 0; i < l; i++)
            {
                if (i > 0)
                {
                    sb.append(",\n");
                }
                Object val = Array.get(obj, i);
                if (cl.getComponentType().isPrimitive())
                {
                    sb.append(val);
                }
                else
                {
                    sb.append(toString(val));
                }
            }
            sb.append("\n}");
            return sb.toString();
        }

        StringBuilder sb = new StringBuilder();
        sb.append(cl.getName());
        // 分析到这个类以及其超类的所有域变量
        do
        {
            sb.append("[");
            Field[] fields = cl.getDeclaredFields();
            AccessibleObject.setAccessible(fields, true);
            // 获取域变量名以及值
            for (Field f : fields)
            {
                if (!Modifier.isStatic(f.getModifiers()))
                {
                    if (!sb.toString().endsWith("["))
                    {
                        sb.append(",");
                    }
                    sb.append(f.getName());
                    sb.append("=");
                    try
                    {
                        Class t = f.getType();
                        Object val = f.get(obj);
                        if (t.isPrimitive())
                        {
                            sb.append(val);
                        }
                        else
                        {
                            sb.append(toString(val));
                        }
                    }
                    catch (Exception e)
                    {
                        e.printStackTrace();
                    }
                }
            }
            sb.append("]");
            cl = cl.getSuperclass();
        }
        while (cl != null);
        return sb.toString();
    }
}
