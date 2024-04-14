/**
 * @file 242. Valid Anagram(easy)-哈希表法.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int count[26];
        memset(count, 0, sizeof(count));
        for (char c : s)
        {
            ++count[c - 'a'];
        }
        for (char c : t)
        {
            if (count[c - 'a'] == 0)
            {
                return false;
            }
            
            --count[c - 'a'];
        }
        return true;
    }
};
