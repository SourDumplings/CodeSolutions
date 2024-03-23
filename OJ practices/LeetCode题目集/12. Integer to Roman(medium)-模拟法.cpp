/**
 * @file 12. Integer to Roman(medium)-模拟法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 
 * https://leetcode.cn/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    string intToRoman(int num)
    {
        const pair<int, string> valueSymbols[] = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"},
        };
        string res;
        for (const auto &[value, symbols] : valueSymbols)
        {
            while (value <= num)
            {
                num -= value;
                res += symbols;
            }
        }

        return res;
    }
};