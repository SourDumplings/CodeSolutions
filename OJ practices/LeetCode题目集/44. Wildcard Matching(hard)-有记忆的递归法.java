/*
 * @Author: SourDumplings
 * @Date: 2020-02-26 17:38:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/wildcard-matching/
 */

class Solution
{
    private int[][] dp;
    private int lp, ls;

    public boolean isMatch(String s, String p)
    {
        // 清理输入数据，用一个 * 代替多个 *
        StringBuilder sb = new StringBuilder();
        lp = p.length();
        ls = s.length();
        boolean firstStart = true;
        for (int i = 0; i < lp; i++)
        {
            char c = p.charAt(i);
            if (c == '*')
            {
                if (firstStart)
                {
                    sb.append(c);
                    firstStart = false;
                }
            }
            else
            {
                firstStart = true;
                sb.append(c);
            }
        }
        p = sb.toString();
        lp = p.length();

        dp = new int[ls + 1][lp + 1];
        for (int[] ints : dp)
        {
            Arrays.fill(ints, -1);
        }

        return doIsMatch(s, 0, p, 0);
    }

    private boolean doIsMatch(String s, int is, String p, int ip)
    {
        if (dp[is][ip] == -1)
        {
            boolean res;
            if (ls == is)
            {
                res = ip == lp || p.substring(ip).equals("*");
            }
            else if (lp == ip)
            {
                res = false;
            }
            else
            {
                char cs = s.charAt(is);
                char cp = p.charAt(ip);
                if (cs == cp || cp == '?')
                {
                    res = doIsMatch(s, is + 1, p, ip + 1);
                }
                else if (cp == '*')
                {
                    int nextP = ip + 1;
                    if (doIsMatch(s, is + 1, p, ip))
                    {
                        res = true;
                    }
                    else
                    {
                        if (nextP == lp)
                        {
                            res = true;
                        }
                        else
                        {
                            res = doIsMatch(s, is, p, nextP);
                        }
                    }
                }
                else
                {
                    res = false;
                }
            }
            dp[is][ip] = res ? 1 : 0;
        }

        return dp[is][ip] == 1;
    }
}
