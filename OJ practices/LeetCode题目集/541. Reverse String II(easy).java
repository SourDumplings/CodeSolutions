/*
 * @Author: SourDumplings
 * @Date: 2019-10-03 23:38:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-string-ii/
 */

class Solution
{
    public String reverseStr(String s, int k)
    {
        int l = s.length();
        char[] str = s.toCharArray();
        for (int i = 0; i < l; i += 2 * k)
        {
            int e = i + k < l ? i + k : l;
            for (int j = i; j < (i + e) / 2; j++)
            {
                char temp = str[j];
                str[j] = str[e + i - j - 1];
                str[e + i - j - 1] = temp;
            }
        }
        return String.copyValueOf(str);
    }
}