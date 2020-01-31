/*
 * @Author: SourDumplings
 * @Date: 2019-10-14 14:40:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-palindrome-ii/
 * 
 * 和使用额外字符串思路其实是一样的，只不过不用额外字符串，给判断回文序列的函数传入范围参数即可
 */

class Solution
{
    public boolean validPalindrome(String s)
    {
        int i = 0, j = s.length() - 1;
        boolean flag = true;
        while (i < j)
        {
            if (s.charAt(i) != s.charAt(j))
            {
                flag = isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
                break;
            }
            ++i;
            --j;
        }
        return flag;
    }

    private boolean isPalindrome(String s, int f, int l)
    {
        while (f < l)
        {
            if (s.charAt(f) != s.charAt(l))
                return false;
            ++f;
            --l;
        }
        return true;
    }
}