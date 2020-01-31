/*
 * @Author: SourDumplings
 * @Date: 2020-01-07 21:55:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/string-to-integer-atoi/
 */

class Solution
{
public:
    int myAtoi(string str)
    {
        string valueStr;
        int i = 0;
        while (str[i] == ' ')
            ++i;
        bool isFirst = true;
        int l = str.length();
        for (; i < l; i++)
        {
            char c = str[i];
            if (isFirst)
            {
                if (isdigit(c) || c == '-')
                {
                    valueStr += c;
                }
                else if (c != '+')
                {
                    break;
                }
                isFirst = false;
            }
            else
            {
                if (isdigit(c))
                {
                    valueStr += c;
                }
                else
                {
                    break;
                }
            }
        }
        if (valueStr == "-" || valueStr.empty())
        {
            return 0;
        }
        double value = stod(valueStr);
        const int MAX = 2147483647;
        const int MIN = -2147483648;
        if (value > MAX)
        {
            return MAX;
        }
        else if (value < MIN)
        {
            return MIN;
        }
        else
        {
            return value;
        }
    }
};