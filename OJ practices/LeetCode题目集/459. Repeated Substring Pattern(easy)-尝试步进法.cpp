/*
 * @Author: SourDumplings
 * @Date: 2019-09-26 16:07:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/repeated-substring-pattern/
 * 
 * 思路就是尝试第一个子串和第二个之间的距离，看能否找到一个，时间复杂度为O(n^2)
 */

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int l = s.length();
        for (int d = 1; d < l; d++)
        {
            for (int i = 0; i < l - d; ++i)
            {
                if (s[i] != s[i + d])
                {
                    break;
                }
                if (l % d == 0 && i + d == l - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};