/*
 * @Author: SourDumplings
 * @Date: 2020-02-26 17:38:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/wildcard-matching/
 */

class Solution
{
    public boolean isMatch(String s, String p)
    {
        return doIsMatch(s, 0, p, 0);
    }

    private boolean doIsMatch(String s, int is, String p, int ip)
    {
        int ls = s.length(), lp = p.length();
        if (ls == is)
        {
            for (; ip < lp && p.charAt(ip) == '*'; ++ip)
                ;
            return ip == lp;
        }
        else if (lp == ip)
        {
            return ls == is;
        }
        else
        {
            char cs = s.charAt(is);
            char cp = p.charAt(ip);
            if (cs == cp || cp == '?')
            {
                return doIsMatch(s, is + 1, p, ip + 1);
            }
            else if (cp == '*')
            {
                int nextP = ip + 1;
                if (doIsMatch(s, is + 1, p, ip))
                {
                    return true;
                }
                else
                {
                    for (; nextP < lp && p.charAt(nextP) == '*'; ++nextP)
                        ;
                    if (nextP == lp)
                    {
                        return true;
                    }
                    else
                    {
                        return doIsMatch(s, is, p, nextP);
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
}