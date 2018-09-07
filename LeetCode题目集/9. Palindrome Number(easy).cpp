/*
 @Date    : 2018-01-26 09:29:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/palindrome-number/description/
 */

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        char temp_s[100];
        sprintf(temp_s, "%d", x);
        int l = strlen(temp_s);
        for (int i = 0, j = l - 1; i <= j; ++i, --j)
        {
            if (temp_s[i] != temp_s[j])
                return false;
        }
        return true;
    }
};
