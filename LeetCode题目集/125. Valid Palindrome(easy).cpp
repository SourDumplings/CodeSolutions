/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-palindrome/
 * @Date: 2019-03-20 18:31:23
 */

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        int l = s.length();
        string str;
        str.resize(l);
        int j = 0;
        for (int i = 0; i < l; i++)
        {
            if (isalnum(s[i]))
            {
                str[j++] = tolower(s[i]);
            }
        }
        for (int i = 0; i < j / 2; i++)
        {
            if (str[i] != str[j - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};