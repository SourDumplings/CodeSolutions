/*
 * @Autor: SourDumplings
 * @Date: 2019-09-19 09:04:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/first-unique-character-in-a-string/
 */

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> m;
        for (auto &&c : s)
        {
            if (m.find(c) == m.end())
            {
                m[c] = 1;
            }
            else
            {
                ++m[c];
            }
        }
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            char c = s[i];
            if (m[c] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};