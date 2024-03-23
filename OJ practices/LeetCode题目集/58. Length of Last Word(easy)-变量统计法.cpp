/**
 * @file 58. Length of Last Word(easy)-变量统计法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/length-of-last-word/submissions/515496490/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int res = 0;
        int thisWordLength = 0;
        for (char c : s)
        {
            if (c == ' ')
            {
                if (0 < thisWordLength)
                {
                    res = thisWordLength;
                    thisWordLength = 0;
                }
            }
            else
            {
                ++thisWordLength;
            }
        }

        if (0 < thisWordLength)
        {
            res = thisWordLength;
        }
        return res;
        
    }
};
