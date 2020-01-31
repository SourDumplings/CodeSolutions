/*
 * @Author: SourDumplings
 * @Date: 2019-09-29 18:22:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-uncommon-subsequence-i/
 */

class Solution
{
    public int findLUSlength(String a, String b)
    {
        int la = a.length();
        int lb = b.length();
        if (a.equals(b))
        {
            return -1;
        }
        else
        {
            return la < lb ? lb : la;
        }
    }
}