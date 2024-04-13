/**
 * @file 383. Ransom Note(easy).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int resNum[26];
        memset(resNum, 0, sizeof(resNum));
        for (char c : magazine)
        {
            ++resNum[c - 'a'];
        }
        for (char c : ransomNote)
        {
            if (resNum[c - 'a'] == 0)
            {
                return false;
            }
            --resNum[c - 'a'];
        }
        return true;
    }
};