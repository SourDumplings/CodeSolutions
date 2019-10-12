/**
 * @Date    : 2019-01-06 22:35:54
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/longest-common-prefix/
*/

class Solution
{
    public String longestCommonPrefix(String[] strs)
    {
        if (strs.length == 0)
            return "";
        String prefix = strs[0];
        for (int i = 1; i != strs.length; ++i)
        {
            while (strs[i].indexOf(prefix) != 0)
            {
                prefix = prefix.substring(0, prefix.length() - 1);
            }
            if (prefix.isEmpty())
                return "";
        }
        return prefix;
    }
}

