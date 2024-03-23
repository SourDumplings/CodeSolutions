/**
 * @file 12. Integer to Roman(medium)-硬编码数字法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/integer-to-roman/solutions/774611/zheng-shu-zhuan-luo-ma-shu-zi-by-leetcod-75rs/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    string intToRoman(int num)
    {
        const string thousands[] = { "", "M", "MM", "MMM" };
        const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        string res;
        for (int i = 1000; 0 < i; i /= 10)
        {
            const string *p = nullptr;
            switch (i)
            {
            case 1000:
                p = thousands;
                break;
            case 100:
                p = hundreds;
                break;
            case 10:
                p = tens;
                break;
            case 1:
                p = ones;
                break;

            default:
                break;
            }

            res += *(p + num / i);
            num = num % i;
        }
        return res;
    }
};