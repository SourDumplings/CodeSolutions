/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-palindrome/
 * @Date: 2019-03-20 18:43:18
 */

class Solution
{
    public boolean isPalindrome(String s)
    {
        StringBuffer str = new StringBuffer();
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            char c = s.charAt(i);
            if (Character.isAlphabetic(c) || Character.isDigit(c))
            {
                str.append(Character.toLowerCase(c));
            }
        }
        int ll = str.length();
        for (int i = 0; i < ll / 2; ++i)
        {
            if (str.charAt(i) != str.charAt(ll - i - 1))
            {
                return false;
            }
        }
        return true;
    }
}