import java.util.Arrays;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-26 10:40:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/assign-cookies/
 */

class Solution
{
    public int findContentChildren(int[] g, int[] s)
    {
        Arrays.sort(g);
        Arrays.sort(s);
        int res = 0;
        int i = 0;
        int n = s.length;
        for (int c : g)
        {
            while (i < n && s[i] < c)
            {
                ++i;
            }
            if (i == n)
            {
                break;
            }
            ++res;
            ++i;
        }
        return res;
    }
}