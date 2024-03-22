/**
 * @file 13. Roman to Integer(easy)-单元素考察.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            char c = s[i];
            char next = i < l - 1 ? s[i + 1] : '\0';
            int add = 0;
            switch (c)
            {
            case 'I':
            {
                if (next == 'V')
                {
                    add = 4;
                    ++i;
                }
                else if (next == 'X')
                {
                    add = 9;
                    ++i;
                }
                else
                {
                    add = 1;
                }
                break;
            }
            case 'V':
            {
                add = 5;
                break;
            }
            case 'X':
            {
                if (next == 'L')
                {
                    add = 40;
                    ++i;
                }
                else if (next == 'C')
                {
                    add = 90;
                    ++i;
                }
                else
                {
                    add = 10;
                }
                break;
            }
            case 'L':
            {
                add = 50;
                break;
            }
            case 'C':
            {
                if (next == 'D')
                {
                    add = 400;
                    ++i;
                }
                else if (next == 'M')
                {
                    add = 900;
                    ++i;
                }
                else
                {
                    add = 100;
                }
                break;
            }
            case 'D':
            {
                add = 500;
                break;
            }
            case 'M':
            {
                add = 1000;
                break;
            }

            default:
                break;
            }
            res += add;
        }
        return res;
    }
};