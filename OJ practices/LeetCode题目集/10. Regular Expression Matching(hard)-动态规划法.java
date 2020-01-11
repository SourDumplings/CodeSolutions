/*
 * @Autor: SourDumplings
 * @Date: 2020-01-11 08:31:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/regular-expression-matching/
 * 
 * 思路和递归法大体相似，只不过我们记录并利用中间结果来代替去匹配 s[i:] 和 p[j:]
 * 大大减少了重复计算
 * 所谓 dp(i, j) 就是计算 s[i:] 和 p[j:] 是否匹配
 */

class Solution
{
    private Boolean res[][];

    public boolean isMatch(String s, String p)
    {
        res = new Boolean[s.length() + 1][p.length() + 1];
        return dp(s, 0, p, 0);
    }

    private boolean dp(String s, int i, String p, int j)
    {
        if (res[i][j] == null)
        {
            if (j == p.length())
            {
                res[i][j] = i == s.length();
            }
            else
            {
                boolean firstMatch = (i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.'));

                if (j < p.length() - 1 && p.charAt(j + 1) == '*')
                {
                    res[i][j] = (dp(s, i, p, j + 2) || (firstMatch && dp(s, i + 1, p, j)));
                }
                else
                {
                    res[i][j] = (firstMatch && dp(s, i + 1, p, j + 1));
                }
            }
        }
        return res[i][j];
    }
}
