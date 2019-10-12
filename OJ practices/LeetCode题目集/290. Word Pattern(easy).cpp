/*
 * @Author: SourDumplings
 * @Date: 2019-09-06 10:34:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/word-pattern/
 */

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        istringstream is(str);
        map<char, string> m1;
        map<string, char> m2;
        for (auto &&c : pattern)
        {
            string s;
            if (is.eof())
            {
                return false;
            }

            is >> s;
            if (m1.find(c) == m1.end())
            {
                if (m2.find(s) == m2.end())
                {
                    m1[c] = s;
                    m2[s] = c;
                }
                else
                {
                    return false;
                }
            }
            else if (m1[c] != s)
            {
                return false;
            }
        }
        if (is.eof())
        {
            return true;
        }
        return false;
    }
};