import java.util.ArrayList;
import java.util.List;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 20:10:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/string-compression/
 */

class Solution
{
    private int count = 0;
    private char lastChar = (char) 0;

    public int compress(char[] chars)
    {
        List<Character> res = new ArrayList<>();
        for (char c : chars)
        {
            if (c == lastChar)
            {
                ++count;
            }
            else
            {
                record(lastChar, res);
                count = 1;
                lastChar = c;
            }
        }
        record(lastChar, res);
        int l = res.size();
        int i = 0;
        for (char c : res)
        {
            chars[i++] = c;
        }
        return l;
    }

    void record(char c, List<Character> res)
    {
        if (count == 1)
        {
            res.add(c);
        }
        else if (count > 1)
        {
            res.add(c);
            String num = String.valueOf(count);
            int l = num.length();
            for (int i = 0; i < l; i++)
            {
                char d = num.charAt(i);
                res.add(d);
            }
        }
    }
}