/*
 * @Autor: SourDumplings
 * @Date: 2019-09-26 16:16:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/repeated-substring-pattern/
 * 
 * 直接使用String的match方法利用正则表达式进行匹配每一个前缀子串，
 * 注意先判断前缀子串的长度是否是总长度的约数进行剪枝，否则会超时
 */

class Solution
{
    public boolean repeatedSubstringPattern(String s)
    {
        int l = s.length();
        for (int i = 1; i <= l / 2; i++)
        {
            if (l % i == 0 && s.matches("(" + s.substring(0, i) + ")+"))
            {
                return true;
            }
        }
        return false;
    }
}