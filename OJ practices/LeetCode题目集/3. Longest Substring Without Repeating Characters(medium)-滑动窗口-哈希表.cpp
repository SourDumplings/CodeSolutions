/**
 * @file 3. Longest Substring Without Repeating Characters(medium)-哈希表.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief https://leetcode.cn/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-04-06
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 复杂度：时间 O(n)，空间 O(n)
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }

        unordered_map<int, int> m;
        int l = 0, r = 1;
        int res = 1;
        m[s[l]] = 0;
        while (r < n)
        {
            char c = s[r];
            auto it = m.find(c);
            if (it != m.end())
            {
                if (res < r - l)
                {
                    res = r - l;
                }
                int nextL = it->second + 1;
                while (l < nextL)
                {
                    m.erase(s[l]);
                    ++l;
                }
            }
            m[s[r]] = r;
            ++r;
        }
        if (res < r - l)
        {
            res = r - l;
        }
        return res;
    }
};