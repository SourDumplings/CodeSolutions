/*
 * @Autor: SourDumplings
 * @Date: 2019-10-20 10:52:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/count-binary-substrings/
 * 
 * 思路和记录连续位法一样，只不过group数组多余了
 * 其实只需要两个元素一个记上一个，一个记上上一个即可
 */

class Solution
{
    public int countBinarySubstrings(String s)
    {
        int l = s.length();
        int last2 = 0, last1 = 1;
        int res = 0;
        for (int i = 1; i < l; i++)
        {
            if (s.charAt(i - 1) != s.charAt(i))
            {
                res += Math.min(last1, last2);
                last2 = last1;
                last1 = 1;
            }
            else
            {
                ++last1;
            }
        }
        res += Math.min(last1, last2);
        return res;
    }
}
