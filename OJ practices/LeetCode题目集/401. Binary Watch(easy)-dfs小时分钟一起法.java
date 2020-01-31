import java.util.ArrayList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-22 08:58:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-watch/
 * 
 * 用正数表示小时，负数表示分钟，放在一起dfs
 */

class Solution
{
    private int[] power =
    { 1, 2, 4, 8, -1, -2, -4, -8, -16, -32 };

    public List<String> readBinaryWatch(int num)
    {
        List<String> res = new ArrayList<>();
        if (num == 0)
        {
            res.add("0:00");
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                dfs(res, i, num - 1, 0, 0);
            }
        }
        return res;

    }

    public void dfs(List<String> res, int b, int n, int h, int m)
    {
        int value = power[b];
        if (value < 0)
        {
            m -= value;
        }
        else
        {
            h += value;
        }

        if (n == 0)
        {
            if (h < 12 && m < 60)
            {
                process(res, h, m);
            }
        }
        else
        {
            for (int i = b + 1; i < 10; i++)
            {
                dfs(res, i, n - 1, h, m);
            }
        }

        if (value < 0)
        {
            m += value;
        }
        else
        {
            h -= value;
        }
    }

    public void process(List<String> res, int h, int m)
    {
        StringBuilder sBuilder = new StringBuilder();
        sBuilder.append(String.valueOf(h));
        sBuilder.append(":");
        if (m < 10)
        {
            sBuilder.append("0");
        }
        sBuilder.append(String.valueOf(m));
        res.add(sBuilder.toString());
    }
}