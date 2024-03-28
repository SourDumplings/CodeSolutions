/**
 * @file 392. Is Subsequence(easy).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        int ls = s.length(), lt = t.length();
        while (i < ls)
        {
            while (j < lt && s[i] != t[j])
            {
                ++j;
            }
            if (j == lt)
            {
                return false;
            }
            ++i;
            ++j;            
        }
        return true;
    }
};