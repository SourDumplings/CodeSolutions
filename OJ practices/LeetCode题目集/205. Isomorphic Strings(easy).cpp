/**
 * @file 205. Isomorphic Strings(easy).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int l = s.length();
        char m[200];
        char rm[200];
        memset(m, -1, sizeof(m));
        memset(rm, -1, sizeof(rm));
        for (int i = 0; i < l; ++i)
        {
            if (m[s[i]] == -1)
            {
                m[s[i]] = t[i];
                if (rm[t[i]] != -1)
                {
                    return false;
                }
                rm[t[i]] = s[i];
                
            }
            else if (m[s[i]] != t[i])
            {
                return false;
            }
            else if (rm[t[i]] != s[i])
            {
                return false;
            }
            
        }
        return true;
    }
};