/*
 * @Author: SourDumplings
 * @Date: 2019-09-24 16:04:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/add-strings/
 */

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res;
        int l1 = num1.length();
        int l2 = num2.length();
        if (l1 < l2)
        {
            swap(num1, num2);
            swap(l1, l2);
        }
        bool isCarry = false;
        for (int i = l2 - 1; i >= 0; i--)
        {
            int r = num2[i] - '0' + num1[i + l1 - l2] - '0';
            if (isCarry)
            {
                r++;
                isCarry = false;
            }

            char d;
            if (r > 9)
            {
                r -= 10;
                isCarry = true;
            }
            d = r + '0';
            res += d;
        }
        for (int i = l1 - l2 - 1; i >= 0; i--)
        {
            int r = num1[i] - '0';
            if (isCarry)
            {
                r++;
                isCarry = false;
            }
            if (r > 9)
            {
                r -= 10;
                isCarry = true;
            }
            res += r + '0';
        }

        if (isCarry)
        {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};