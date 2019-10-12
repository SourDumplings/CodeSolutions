/**
 * @Date    : 2019-01-06 23:18:51
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/longest-common-prefix/solution/
*/

class Solution
{
    public String longestCommonPrefix(String[] strs)
    {
        if (strs == null || strs.length == 0)
        {
            return "";
        }
        for (int prefixL = 0; prefixL != strs[0].length(); ++prefixL)
        {
            char c = strs[0].charAt(prefixL);
            for (int i = 1; i != strs.length; ++i)
            {
                if (strs[i].length() == prefixL || strs[i].charAt(prefixL) != c)
                {
                    return strs[i].substring(0, prefixL);
                }
            }
        }
        return strs[0];
    }
}


