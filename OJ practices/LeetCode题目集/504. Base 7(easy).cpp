/*
 * @Autor: SourDumplings
 * @Date: 2019-09-28 13:37:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/base-7/
 */

class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }

        string res;
        bool negative = false;
        if (num < 0)
        {
            num = -num;
            negative = true;
        }

        while (num != 0)
        {
            res += num % 7 + '0';
            num /= 7;
        }
        if (negative)
        {
            res += '-';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};