/*
 * @Author: SourDumplings
 * @Date: 2019-09-18 22:12:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/ransom-note/
 */

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m;
        for (auto &&c : magazine)
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
        for (auto &&c : ransomNote)
        {
            if (m.find(c) == m.end() || m[c] == 0)
            {
                return false;
            }
            else
            {
                --m[c];
            }
        }
        return true;
    }
};
