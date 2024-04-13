/**
 * @file 290. Word Pattern(easy).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> m;
        unordered_map<string, char> rm;
        int l = pattern.length();
        int b = 0;
        for (int i = 0; i < l; i++)
        {
            if (s.length() <= b)
            {
                return false;
            }

            int e = b + 1;
            for (; e < s.length() && s[e] != ' '; ++e);
            string word = s.substr(b, e - b);
            b = e + 1;
            if (m.find(pattern[i]) == m.end())
            {
                if (rm.find(word) != rm.end())
                {
                    return false;
                }
                
                m[pattern[i]] = word;
                rm[word] = pattern[i];
            }
            else if (m.at(pattern[i]) != word)
            {
                return false;
            }
            
        }
        if (b < s.length() + 1)
        {
            return false;
        }
        return true;
    }
};

