/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 20:36:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/string-compression/
 */

class Solution
{
    public int compress(char[] chars)
    {
        int count = 0;
        char lastChar = (char) 0;
        int i = 0;
        for (char c : chars)
        {
            if (c == lastChar)
            {
                ++count;
            }
            else
            {
                if (count == 1)
                {
                    chars[i++] = lastChar;
                }
                else if (count > 1)
                {
                    chars[i++] = lastChar;
                    String num = String.valueOf(count);
                    int l = num.length();
                    for (int j = 0; j < l; j++)
                    {
                        char d = num.charAt(j);
                        chars[i++] = d;
                    }
                }
                count = 1;
                lastChar = c;
            }
        }
        if (count == 1)
        {
            chars[i++] = lastChar;
        }
        else if (count > 1)
        {
            chars[i++] = lastChar;
            String num = String.valueOf(count);
            int l = num.length();
            for (int j = 0; j < l; j++)
            {
                char d = num.charAt(j);
                chars[i++] = d;
            }
        }
        return i;
    }
}