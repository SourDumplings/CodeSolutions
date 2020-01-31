/*
 * @Autor: SourDumplings
 * @Date: 2020-01-31 09:28:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-valid-parentheses/
 * 
 * 设置记录数组a[l]
 * 所有的有效的字符串都是以')'结尾的，故遇到右括号才更新记录数组，若s[i] == ')'：
 * 1. 如果s[i-1] == '('，即...()，则a[i] = a[i-2] + 2
 * 2. 如果s[i-1] == ')'，即...))，且 i - a[i - 1] - 1 的位置为'('，
 * 则a[i] = a[i-1] + 2 + a[i - a[i-1] - 2]
 */

class Solution
{
    public int longestValidParentheses(String s)
    {
        int res = 0;
        int l = s.length();
        if (l == 0)
        {
            return res;
        }
        int[] a = new int[l];
        a[0] = 0;
        for (int i = 1; i < l; i++)
        {
            char thisC = s.charAt(i);
            if (thisC == ')')
            {
                char lastC = s.charAt(i - 1);
                if (lastC == '(')
                {
                    a[i] = 2;
                    if (i - 2 >= 0)
                    {
                        a[i] += a[i - 2];
                    }
                }
                else if (i - a[i - 1] - 1 >= 0 && s.charAt(i - a[i - 1] - 1) == '(')
                {
                    a[i] = a[i - 1] + 2;
                    if (i - a[i - 1] - 2 >= 0)
                    {
                        a[i] += a[i - a[i - 1] - 2];
                    }
                }
                if (a[i] > res)
                {
                    res = a[i];
                }
            }
            else
            {
                a[i] = 0;
            }
        }
        return res;
    }
}