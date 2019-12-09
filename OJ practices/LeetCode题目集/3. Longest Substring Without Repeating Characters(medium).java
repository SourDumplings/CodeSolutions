/*
 * @Autor: SourDumplings
 * @Date: 2019-12-09 14:21:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
    public int lengthOfLongestSubstring(String s)
    {
        int res = 0;
        StringBuilder thisStr = new StringBuilder();
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            String c = s.substring(i, i + 1);
            int lastOccur = thisStr.indexOf(c);
            if (lastOccur != -1)
            {
                if (thisStr.toString().length() > res)
                {
                    res = thisStr.toString().length();
                }
                thisStr = thisStr.delete(0, lastOccur + 1);
            }
            thisStr.append(c);
        }
        if (thisStr.toString().length() > res)
        {
            res = thisStr.toString().length();
        }
        return res;
    }
}