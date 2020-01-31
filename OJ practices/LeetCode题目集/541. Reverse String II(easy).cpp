/*
 * @Author: SourDumplings
 * @Date: 2019-10-03 23:07:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-string-ii/
 */

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int l = s.length();
        for (int i = 0; i < l; i += 2 * k)
        {
            int e = i + k < l ? i + k : l;
            for (int j = i; j < (i + e) / 2; j++)
            {
                swap(s[j], s[e + i - j - 1]);
            }
        }
        return s;
    }
};