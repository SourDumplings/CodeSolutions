/**
 * @file 12. Integer to Roman(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 数字转罗马字符串，硬编码
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        int t = num / 1000;
        int r = num % 1000;
        for (int i = 0; i < t; i++)
        {
            res += 'M';
        }
        if (900 <= r)
        {
            r -= 900;
            res += "CM";
        }
        else if (400 <= r && r < 500)
        {
            r -= 400;
            res += "CD";
        }
        else if (500 <= r)
        {
            r -= 500;
            res += 'D';
        }
        t = r / 100;
        r = r % 100;
        for (int i = 0; i < t; i++)
        {
            res += 'C';
        }
        if (90 <= r)
        {
            res += "XC";
            r -= 90;
        }
        else if (40 <= r && r < 50)
        {
            res += "XL";
            r -= 40;
        }
        else if (50 <= r)
        {
            res += 'L';
            r -= 50;
        }
        t = r / 10;
        r = r % 10;
        for (int i = 0; i < t; i++)
        {
            res += 'X';
        }
        if (r == 9)
        {
            res += "IX";
            r -= 9;
        }
        else if (r == 4)
        {
            res += "IV";
            r -= 4;
        }
        else if (5 <= r)
        {
            res += 'V';
            r -= 5;
        }
        t = r;
        for (int i = 0; i < t; i++)
        {
            res += 'I';
        }
        return res;
    }
};