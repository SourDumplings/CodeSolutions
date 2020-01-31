/*
 * @Author: SourDumplings
 * @Date: 2019-09-21 17:42:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/is-subsequence/
 */

class Solution
{
    public boolean isSubsequence(String s, String t)
    {
        int j = 0;
        int ls = s.length();
        int lt = t.length();
        if (lt == 0 && ls > 0)
        {
            return false;
        }
        for (int i = 0; i < ls; i++)
        {
            char ci = s.charAt(i);
            for (; j < lt; j++)
            {
                char cj = t.charAt(j);
                if (ci == cj)
                {
                    ++j;
                    break;
                }
            }
            if (j == lt && ci != t.charAt(j - 1))
            {
                return false;
            }
        }
        return true;
    }
}