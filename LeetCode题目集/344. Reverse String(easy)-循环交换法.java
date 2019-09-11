/*
 * @Autor: SourDumplings
 * @Date: 2019-09-11 08:54:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-string/
 */

class Solution
{
    public void reverseString(char[] s)
    {
        int l = s.length;
        for (int i = 0; i < l / 2; i++)
        {
            char temp = s[i];
            s[i] = s[l - 1 - i];
            s[l - i - 1] = temp;
        }
    }
}