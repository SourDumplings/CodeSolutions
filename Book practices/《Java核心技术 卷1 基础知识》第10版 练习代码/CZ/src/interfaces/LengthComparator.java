package interfaces;

import java.util.Comparator;

/**
 * @author Chang Zheng
 * @title: LengthComparator
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2611:07
 */
public class LengthComparator implements Comparator<String>
{
    public int compare(String first, String second)
    {
        return first.length() - second.length();
    }
}
