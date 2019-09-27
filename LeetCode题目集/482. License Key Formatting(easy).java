/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 14:22:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/license-key-formatting/
 */

class Solution
{
    public String licenseKeyFormatting(String S, int K)
    {
        StringBuilder s = new StringBuilder();
        int L = S.length();
        for (int i = 0; i < L; i++)
        {
            char c = S.charAt(i);
            if (c != '-')
            {
                s.append(c);
            }
        }
        String temp = s.toString().toUpperCase();
        int l = temp.length();
        int first = l % K;
        boolean isFirst = (first != 0 && K < l);
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < l; i++)
        {
            char c = temp.charAt(i);
            res.append(c);
            if (isFirst)
            {
                if (i + 1 == first)
                {
                    res.append('-');
                    isFirst = false;
                }
            }
            else if ((i - first + 1) % K == 0 && i != l - 1)
            {
                res.append('-');
            }
        }
        return res.toString();
    }
}