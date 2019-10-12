/**
 * @Date    : 2019-01-23 21:13:34
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/length-of-last-word/
*/

class Solution
{
    public int lengthOfLastWord(String s)
    {
        String[] res = s.trim().split(" ");
        if (res.length == 0)
        {
            return 0;
        }
        else
            return res[res.length-1].length();
    }
}
