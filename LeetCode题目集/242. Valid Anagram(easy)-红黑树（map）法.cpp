/*
 * @Author: SourDumplings
 * @Date: 2019-08-29 12:51:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-anagram/
 */

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> m1, m2;
        for (auto &&c : s)
        {
            ++m1[c];
        }
        for (auto &&c : t)
        {
            ++m2[c];
        }
        return m1 == m2;
    }
};