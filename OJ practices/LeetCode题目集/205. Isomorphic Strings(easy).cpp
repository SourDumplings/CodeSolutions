/*
 * @Author: SourDumplings
 * @Date: 2019-08-18 09:40:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/isomorphic-strings/
 */
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int l = s.length();
        if (l != t.length())
        {
            return false;
        }

        map<char, char> m1, m2;
        for (int i = 0; i < l; i++)
        {
            if (m1.find(s[i]) == m1.end())
            {
                if (m2.find(t[i]) != m2.end())
                {
                    return false;
                }

                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else
            {
                if (m1[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};