package randomAccess;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

/**
 * 用字节流I/O来处理字符串，用0值字符做结束符
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/2121:29
 */
public class DataIO
{
    /**
     * 写出从字符串开头开始的指定数量的码元 如果码元过少则用0值来补齐字符串
     *
     * @param s
     * @param size
     * @param out
     * @throws IOException
     */
    public static void writeFixedString(String s, int size, DataOutput out) throws IOException
    {
        for (int i = 0; i < size; i++)
        {
            char ch = 0;
            if (i < s.length())
            {
                ch = s.charAt(i);
            }
            out.writeChar(ch);
        }
    }

    /**
     * 从输入流中读入字符串，直至读入size个码元，或者直至遇到0值的字符
     *
     * @param size
     * @param in
     * @return
     * @throws IOException
     */
    public static String readFixedString(int size, DataInput in) throws IOException
    {
        StringBuilder sb = new StringBuilder(size);
        int i = 0;
        boolean more = true;
        while (more && i < size)
        {
            char ch = in.readChar();
            ++i;
            if (ch == 0)
            {
                more = false;
            }
            else
            {
                sb.append(ch);
            }
        }
        in.skipBytes(2 * (size - i));
        return sb.toString();
    }
}
