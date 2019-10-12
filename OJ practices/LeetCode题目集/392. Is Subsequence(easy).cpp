/*
 * @Autor: SourDumplings
 * @Date: 2019-09-21 17:09:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/is-subsequence/
 */

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int ls = s.length();
        int lt = t.length();
        int j = 0;
        for (int i = 0; i < ls; i++)
        {
            for (; j < lt; j++)
            {
                if (s[i] == t[j])
                {
                    j++;
                    break;
                }
            }
            if (j == lt && s[i] != t[j - 1])
            {
                return false;
            }
        }
        return true;
    }
};
