/*
 * @Author: SourDumplings
 * @Date: 2019-10-14 14:04:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-palindrome-ii/
 */

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        bool flag = false;
        string temp(s);
        while (i < j)
        {
            if (s[i] != s[j])
            {
                flag = true;
                s.erase(s.begin() + i);
                temp.erase(temp.begin() + j);
                break;
            }
            ++i;
            --j;
        }
        if (!flag)
        {
            return true;
        }
        else if (isPalindrome(s) || isPalindrome(temp))
        {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s)
    {
        int l = s.length();
        for (int i = 0; i < l / 2; i++)
        {
            if (s[i] != s[l - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};