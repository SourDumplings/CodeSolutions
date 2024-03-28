/**
 * @file 125. Valid Palindrome(easy).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < n)
        {
            while (l < n && !isalnum(s[l])) ++l;
            while (l <= r && !isalnum(s[r])) --r;
            if (r <= l)
            {
                break;
            }
            
            char lc = tolower(s[l]);
            char rc = tolower(s[r]);
            if (lc != rc)
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};